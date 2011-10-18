/* 
 * lmon.c -- Curses based Performance Monitor for Linux
 * Developer: Nigel Griffiths. 
 */

/*
 * Use the following Makefile (for Linux on POWER)
CFLAGS=-g -D JFS -D GETUSER -Wall -D LARGEMEM -D POWER
LDFLAGS=-lcurses
nmon: lnmon.o
 * end of Makefile
 */
/* #define POWER 1 */
/* #define KERNEL_2_6_18 1 */
/* This adds the following to the disk stats 
	pi_num_threads, 
	pi_rt_priority, 
	pi_policy, 
	pi_delayacct_blkio_ticks 
*/
               

#define RAW(member)      (long)((long)(p->cpuN[i].member)   - (long)(q->cpuN[i].member))
#define RAWTOTAL(member) (long)((long)(p->cpu_total.member) - (long)(q->cpu_total.member)) 

#define VERSION "14g" 
char version[] = VERSION;
static char *SccsId = "nmon " VERSION;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <pwd.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/wait.h>

/* for Disk Busy rain style output covering 100's of diskss on one screen */
const char disk_busy_map_ch[] =
  "_____.....----------++++++++++oooooooooo0000000000OOOOOOOOOO8888888888XXXXXXXXXX##########@@@@@@@@@@*";
/*"00000555551111111111222222222233333333334444444444555555555566666666667777777777888888888899999999991"*/

int extended_disk = 0;	/* report additional data from /proc/diskstats to spreadsheet output */

#define FLIP(variable) if(variable) variable=0; else variable=1;

#ifdef MALLOC_DEBUG
#define MALLOC(argument)        mymalloc(argument,__LINE__)
#define FREE(argument)          myfree(argument,__LINE__)
#define REALLOC(argument1,argument2)    myrealloc(argument1,argument2,__LINE__)
void *mymalloc(int size, int line)
{
void * ptr;
        ptr= malloc(size);
        fprintf(stderr,"0x%x = malloc(%d) at line=%d\n",ptr,size,line);
        return ptr;
}
void myfree(void *ptr,int line)
{
        fprintf(stderr,"free(0x%x) at line=%d\n",ptr,line);
        free(ptr);
}
void *myrealloc(void *oldptr, int size, int line)
{
void * ptr;
        ptr= realloc(oldptr,size);
        fprintf(stderr,"0x%x = realloc(0x%x, %d) at line=%d\n",ptr,oldptr,size,line);
        return ptr;
}
#else
#define MALLOC(argument)        malloc(argument)
#define FREE(argument)          free(argument)
#define REALLOC(argument1,argument2)    realloc(argument1,argument2)
#endif /* MALLOC STUFF */


#define P_CPUINFO	0
#define P_STAT		1
#define P_VERSION	2
#define P_MEMINFO   	3
#define P_UPTIME   	4
#define P_LOADAVG   	5
#define P_NFS   	6
#define P_NFSD   	7
#define P_VMSTAT	8 /* new in 13h */
#define P_NUMBER	9 /* one more than the max */

char *month[12] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
                    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

/* Cut of everything after the first space in callback
 * Delete any '&' just before the space
 */
char *check_call_string (char* callback, const char* name)
{
        char * tmp_ptr = callback;

        if (strlen(callback) > 256) {
                fprintf(stderr,"ERROR nmon: ignoring %s - too long\n", name);
                return (char *) NULL;
        }

        for( ; *tmp_ptr != '\0' && *tmp_ptr != ' ' && *tmp_ptr != '&'; ++tmp_ptr )
                ;

        *tmp_ptr = '\0';

        if( tmp_ptr == callback )
                return (char *)NULL;
        else
                return callback;
}

/* Remove error output to this buffer and display it if NMONDEBUG=1 */
char errorstr[70];
int error_on = 0;
void error(char *err) 
{
	strncpy(errorstr,err,69);
}


/* Default size for smaller files */
#define PROC_MAXBUF   (1024*4)

/* /proc/stat size for 50-ish bytes per CPU */
#define STAT_MAXBUF   (1024*64)

/* /proc/cpuinfo can be 512 bytes per CPU and we allow 256 CPUs */
/* and 20 lines per CPU so boost the buffers for this one */
#define CPUINFO_MAXBUF (512*256)

#define PROC_MAXLINES (20*256*sizeof(char *))

int proc_cpu_done = 0;	/* Flag if we have run function proc_cpu() already in this interval */

int reread =0;
struct {
	FILE *fp;
	char *filename;
	int lines;
	char *line[PROC_MAXLINES];
	char *buf;
	int read_this_interval; /* track updates for each update to stop  double data collection */
} proc[P_NUMBER];

void proc_init()
{
int i;
	/* Initialise the file pointers */
	for(i=0;i<P_NUMBER;i++) {
		proc[i].fp = 0;
		proc[i].read_this_interval = 0;

		if(i == P_CPUINFO)
			proc[i].buf  = (char *)malloc(CPUINFO_MAXBUF);
		else if(i == P_STAT)
			proc[i].buf  = (char *)malloc(STAT_MAXBUF);
		else
			proc[i].buf  = (char *)malloc(PROC_MAXBUF);
	}
	proc[P_CPUINFO].filename = "/proc/cpuinfo";
	proc[P_STAT].filename    = "/proc/stat";
	proc[P_VERSION].filename = "/proc/version";
	proc[P_MEMINFO].filename = "/proc/meminfo";
	proc[P_UPTIME].filename  = "/proc/uptime";
	proc[P_LOADAVG].filename = "/proc/loadavg";
	proc[P_NFS].filename     = "/proc/net/rpc/nfs";
	proc[P_NFSD].filename    = "/proc/net/rpc/nfsd";
	proc[P_VMSTAT].filename	 = "/proc/vmstat";
}

void proc_read(int num)
{
int i;
int size;
int found;
char buf[1024];
int bytes;

	if(proc[num].read_this_interval == 1 )
		return;

	if(proc[num].fp == 0) {
		if( (proc[num].fp = fopen(proc[num].filename,"r")) == NULL) {
			sprintf(buf, "failed to open file %s", proc[num].filename);
			error(buf);
			proc[num].fp = 0;
			return;
		}
	}
	rewind(proc[num].fp);

	/* We re-read P_STAT, now flag proc_cpu() that it has to re-process that data */
	if( num == P_STAT)
		proc_cpu_done = 0;

	if(num == P_CPUINFO)
		bytes = CPUINFO_MAXBUF -1;
	else if(num == P_STAT)
		bytes = STAT_MAXBUF -1;
	else
		bytes = PROC_MAXBUF -1;

	size = fread(proc[num].buf, 1, bytes, proc[num].fp);

	proc[num].buf[size]=0;
	proc[num].lines=0;
	proc[num].line[0]=&proc[num].buf[0];
	if(num == P_VERSION) {
		found=0;
		for(i=0;i<size;i++) { /* remove some weird stuff found the hard way in various Linux versions and device drivers */
			/* place ") (" on two lines */
			if( found== 0 &&
		 	    proc[num].buf[i]   == ')' &&
			    proc[num].buf[i+1] == ' ' &&
			    proc[num].buf[i+2] == '(' ) {
				proc[num].buf[i+1] = '\n';
				found=1;
			} else {
			    /* place ") #" on two lines */
			    if( proc[num].buf[i]   == ')' &&
			    proc[num].buf[i+1] == ' ' &&
			    proc[num].buf[i+2] == '#' ) {
				proc[num].buf[i+1] = '\n';
			    }
			    /* place "#1" on two lines */
			    if(
		 	    proc[num].buf[i]   == '#' &&
			    proc[num].buf[i+2] == '1' ) {
				proc[num].buf[i] = '\n';
			    }
			}
		}
	}
	for(i=0;i<size;i++) {
		/* replace Tab characters with space */
		if(proc[num].buf[i] == '\t')	{
			proc[num].buf[i]= ' '; 
		}
		else if(proc[num].buf[i] == '\n') {
			/* replace newline characters with null */
			proc[num].lines++;
			proc[num].buf[i] = '\0';
			proc[num].line[proc[num].lines] = &proc[num].buf[i+1];
		}
		if(proc[num].lines==PROC_MAXLINES-1)
			break;
	}
	if(reread) {
		fclose( proc[num].fp);
		proc[num].fp = 0;
	}
	/* Set flag so we do not re-read the data even if called multiple times in same interval */
	proc[num].read_this_interval = 1;
}

#include <dirent.h>

struct procsinfo {
                int pi_pid;
                char pi_comm[64];
                char pi_state;
                int pi_ppid;
                int pi_pgrp;
                int pi_session;
                int pi_tty_nr;
                int pi_tty_pgrp;
                unsigned long pi_flags;
                unsigned long pi_minflt;
                unsigned long pi_cmin_flt;
                unsigned long pi_majflt;
                unsigned long pi_cmaj_flt;
                unsigned long pi_utime;
                unsigned long pi_stime;
                long pi_cutime;
                long pi_cstime;
                long pi_pri;
                long pi_nice;
#ifndef KERNEL_2_6_18
                long junk /* removed */;
#else
                long pi_num_threads;
#endif
                long pi_it_real_value;
                unsigned long pi_start_time;
                unsigned long pi_vsize;
                long pi_rss; /* - 3 */
                unsigned long pi_rlim_cur;
                unsigned long pi_start_code;
                unsigned long pi_end_code;
                unsigned long pi_start_stack;
                unsigned long pi_esp;
                unsigned long pi_eip;
                /* The signal information here is obsolete. */
                unsigned long pi_pending_signal;
                unsigned long pi_blocked_sig;
                unsigned long pi_sigign;
                unsigned long pi_sigcatch;
                unsigned long pi_wchan;
                unsigned long pi_nswap;
                unsigned long pi_cnswap;
                int pi_exit_signal;
                int pi_cpu;
#ifdef KERNEL_2_6_18
                unsigned long pi_rt_priority;
                unsigned long pi_policy;
                unsigned long long pi_delayacct_blkio_ticks;
#endif
		unsigned long statm_size;       /* total program size */
                unsigned long statm_resident;   /* resident set size */
                unsigned long statm_share;      /* shared pages */
                unsigned long statm_trs;        /* text (code) */
                unsigned long statm_drs;        /* data/stack */
                unsigned long statm_lrs;        /* library */
                unsigned long statm_dt;         /* dirty pages */
};


#include <mntent.h>
#include <fstab.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <net/if.h>

int debug =0;
time_t  timer;			/* used to work out the hour/min/second */

/* Counts of resources */
int	cpus = 1;  	/* number of CPUs in system (lets hope its more than zero!) */
int old_cpus = 1;	/* Number of CPU seen in previuos interval */
int	max_cpus = 1;  	/* highest number of CPUs in DLPAR */
int	networks = 0;  	/* number of networks in system  */
int	partitions = 0;  	/* number of partitions in system  */
int	partitions_short = 0;  	/* partitions file data short form (i.e. data missing) */
int	disks    = 0;  	/* number of disks in system  */
int	seconds  = -1; 	/* pause interval */
int	maxloops = -1;  /* stop after this number of updates */
char	hostname[256];
char	run_name[256];
int	run_name_set = 0;
char	fullhostname[256];
int	loop;

#define DPL 150 /* Disks per line for file output to ensure it 
		does not overflow the spreadsheet input line max */

int disks_per_line = DPL;

#define NEWDISKGROUP(disk) ( (disk) % disks_per_line == 0)

/* Mode of output variables */
int	show_aaa     = 1;
int	show_para    = 1;
int	show_headings= 1;
int	show_cpu     = 0;
int	show_smp     = 0;
int	show_longterm= 0;
int	show_disk    = 0;
#define SHOW_DISK_NONE  0
#define SHOW_DISK_STATS 1
#define SHOW_DISK_GRAPH 2
int	show_diskmap = 0;
int	show_memory  = 0;
int	show_large   = 0;
int	show_kernel  = 0;
int	show_nfs     = 0;
int	show_net     = 0;
int	show_neterror= 0;
int	show_partitions  = 0;
int	show_help    = 0;
int	show_top     = 0;
int	show_topmode = 1;
#define ARGS_NONE 0
#define ARGS_ONLY 1
int	show_args    = 0;
int	show_all     = 1;	/* 1=all procs& disk 0=only if 1% or more busy */
int	show_verbose = 0;
int	show_jfs     = 0;
int	flash_on     = 0;
int	first_huge   = 1;
long	huge_peak    = 0;
int	welcome      = 1;
int	dotline      = 0;
int	show_rrd     = 0;
int	show_lpar    = 0;
int	show_vm    = 0;
int	show_dgroup  = 0; /* disk groups */
int     dgroup_loaded = 0; /* 0 = no, 1=needed, 2=loaded */
int	show_raw    = 0;

#define RRD if(show_rrd)  

double ignore_procdisk_threshold = 0.1;
double ignore_io_threshold      = 0.1;
/* Curses support */
#define CURSE if(cursed)  /* Only use this for single line curses calls */
#define COLOUR if(colour) /* Only use this for single line colour curses calls */
int	cursed = 1;	/* 1 = using curses and 
			   0 = loging output for a spreadsheet */
int	colour = 1;	/* 1 = using colour curses and 
			   0 = using black and white curses  (see -b flag) */
#define MVPRINTW(row,col,string) {move((row),(col)); \
					attron(A_STANDOUT); \
					printw(string); \
					attroff(A_STANDOUT); }
FILE *fp;	/* filepointer for spreadsheet output */


char *timestamp(int loop, time_t eon)
{
static char string[64];
	if(show_rrd)
		sprintf(string,"%ld",(long)eon);
	else
		sprintf(string,"T%04d",loop);
	return string;
}
#define LOOP timestamp(loop,timer)

char *easy[5] = {"not found",0,0,0,0};
char *lsb_release[5] = {"not found",0,0,0,0};

void find_release()
{
FILE *pop;
int i;
char tmpstr[71];

	pop = popen("cat /etc/*ease 2>/dev/null", "r");
	if(pop != NULL) {
		tmpstr[0]=0;
	    	for(i=0;i<4;i++) {
			if(fgets(tmpstr, 70, pop) == NULL) 
				break;
			tmpstr[strlen(tmpstr)-1]=0; /* remove newline */
			easy[i] = malloc(strlen(tmpstr)+1);
			strcpy(easy[i],tmpstr);
		}
		pclose(pop);
	}
	pop = popen("/usr/bin/lsb_release -idrc 2>/dev/null", "r");
	if(pop != NULL) {
		tmpstr[0]=0;
	    	for(i=0;i<4;i++) {
			if(fgets(tmpstr, 70, pop) == NULL) 
				break;
			tmpstr[strlen(tmpstr)-1]=0; /* remove newline */
			lsb_release[i] = malloc(strlen(tmpstr)+1);
			strcpy(lsb_release[i],tmpstr);
		}
		pclose(pop);
	}
}



/* Full Args Mode stuff here */

#define ARGSMAX 1024*8
#define CMDLEN 4096

struct {
	int pid;
	char *args;
} arglist[ARGSMAX];

void args_output(int pid, int loop, char *progname)
{
FILE *pop;
int i,j,n;
char tmpstr[CMDLEN];
static int arg_first_time = 1;

	if(pid == 0)
		return; /* ignore init */
	for(i=0;i<ARGSMAX-1;i++ ) {   /* clear data out */
		if(arglist[i].pid == pid){
			return;
		}
		if(arglist[i].pid == 0) /* got to empty slot */
			break;
	}
	sprintf(tmpstr,"ps -p %d -o args 2>/dev/null", pid);
	pop = popen(tmpstr, "r");
	if(pop == NULL) {
		return;
	} else {
		if(fgets(tmpstr, CMDLEN, pop) == NULL) { /* throw away header */
			pclose(pop);
			return;
		}
		tmpstr[0]=0;
		if(fgets(tmpstr, CMDLEN, pop) == NULL) {
			pclose(pop);
			return;
		}
		tmpstr[strlen(tmpstr)-1]=0;
		if(tmpstr[strlen(tmpstr)-1]== ' ')
			tmpstr[strlen(tmpstr)-1]=0;
		arglist[i].pid = pid;
		if(arg_first_time) {
			fprintf(fp,"UARG,+Time,PID,ProgName,FullCommand\n");
			arg_first_time = 0;
		}
		n=strlen(tmpstr);
		for(i=0;i<n;i++) {
			/*strip out stuff that confused Excel i.e. starting with maths symbol*/
			if(tmpstr[i] == ',' &&
			  ((tmpstr[i+1] == '-') || tmpstr[i+1] == '+')  )
				tmpstr[i+1] = '_';
			/*strip out double spaces */
			if(tmpstr[i] == ' ' && tmpstr[i+1] == ' ') {
				for(j=0;j<n-i;j++)
					tmpstr[i+j]=tmpstr[i+j+1];
				i--; /* rescan to remove triple space etc */
			}
		}

		fprintf(fp,"UARG,%s,%07d,%s,%s\n",LOOP,pid,progname,tmpstr);
		pclose(pop);
		return;
	}
}

void args_load()
{
FILE *pop;
int i;
char tmpstr[CMDLEN];

	for(i=0;i<ARGSMAX;i++ ) {   /* clear data out */
		if(arglist[i].pid == -1)
			break;
		if(arglist[i].pid != 0){
			arglist[i].pid = -1;
			free(arglist[i].args);
		}
	}
	pop = popen("ps -eo pid,args 2>/dev/null", "r");
	if(pop == NULL) {
		return;
	} else {
		if(fgets(tmpstr, CMDLEN, pop) == NULL) { /* throw away header */
			pclose(pop);
			return;
		}
		for(i=0;i<ARGSMAX;i++ ) {
			tmpstr[0]=0;
			if(fgets(tmpstr, CMDLEN, pop) == NULL) {
				pclose(pop);
				return;
			}
			tmpstr[strlen(tmpstr)-1]=0;
			if(tmpstr[strlen(tmpstr)-1]== ' ')
				tmpstr[strlen(tmpstr)-1]=0;
			arglist[i].pid = atoi(tmpstr);
			arglist[i].args = malloc(strlen(tmpstr));
			strcpy(arglist[i].args,&tmpstr[6]);
		}
		pclose(pop);
	}
}

char *args_lookup(int pid, char *progname)
{
int i;
	for(i=0;i<ARGSMAX;i++) {
		if(arglist[i].pid == pid)
			return arglist[i].args;
		if(arglist[i].pid == -1)
			return progname;
	}
	return progname;
}
/* end args mode stuff here */

void   linux_bbbp(char *name, char *cmd, char *err)
{
        int   i;
        int   len;
#define STRLEN 4096
        char   str[STRLEN];
        FILE * pop;
        static int   lineno = 0;

        pop = popen(cmd, "r");
        if (pop == NULL) {
                fprintf(fp, "BBBP,%03d,%s failed to run %s\n", lineno++, cmd, err);
        } else {
                fprintf(fp, "BBBP,%03d,%s\n", lineno++, name);
                for (i = 0; i < 2048 && (fgets(str, STRLEN, pop) != NULL); i++) { /* 2048=sanity check only */
                        len = strlen(str);
			if(len>STRLEN) len=STRLEN;
                        if (str[len-1] == '\n') /*strip off the newline */
                                str[len-1] = 0;
                        /* fix lsconf style output so it does not confuse spread sheets */
                        if(str[0] == '+') str[0]='p';
                        if(str[0] == '*') str[0]='m';
                        if(str[0] == '-') str[0]='n';
                        if(str[0] == '/') str[0]='d';
                        if(str[0] == '=') str[0]='e';
                        fprintf(fp, "BBBP,%03d,%s,\"%s\"\n", lineno++, name, str);
                }
                pclose(pop);
        }
}

#define WARNING "needs root permission or file not present"

/* Global name of programme for printing it */
char	*progname;

/* Main data structure for collected stats.
 * Two versions are previous and current data.
 * Often its the difference that is printed.
 * The pointers are swaped i.e. current becomes the previous
 * and the previous over written rather than moving data around.
 */
struct cpu_stat {
	long long user;
	long long sys;
	long long wait; 
	long long idle;
	long long irq;
	long long softirq;
	long long steal;
	long long nice;
	long long intr;
	long long ctxt;
	long long btime;
	long long procs;
	long long running;
	long long blocked;
	float uptime;
	float idletime;
	float mins1;
	float mins5;
	float mins15;
};

#define ulong unsigned long
struct dsk_stat {	
	char	dk_name[32];
	int	dk_major;
	int	dk_minor;
	long	dk_noinfo;
	ulong	dk_reads;
	ulong	dk_rmerge;
	ulong	dk_rmsec;
	ulong	dk_rkb;
	ulong	dk_writes;
	ulong	dk_wmerge;
	ulong	dk_wmsec;
	ulong	dk_wkb;
	ulong	dk_xfers;
	ulong	dk_bsize;
	ulong	dk_time;
	ulong	dk_inflight;
	ulong	dk_11;
	ulong	dk_partition;
	ulong	dk_blocks; /* in /proc/partitions only */
	ulong	dk_use;
	ulong	dk_aveq;
};

struct mem_stat {
	long memtotal;
	long memfree;
	long memshared;
	long buffers;
	long cached;
	long swapcached;
	long active;
	long inactive;
	long hightotal;
	long highfree;
	long lowtotal;
	long lowfree;
	long swaptotal;
	long swapfree;
#ifdef LARGEMEM
	long dirty;
	long writeback;
	long mapped;
	long slab;
	long committed_as;
	long pagetables;
	long hugetotal;
	long hugefree;
	long hugesize;
#else
	long bigfree;
#endif /*LARGEMEM*/
};

struct vm_stat {
long long nr_dirty;
long long nr_writeback;
long long nr_unstable;
long long nr_page_table_pages;
long long nr_mapped;
long long nr_slab;
long long pgpgin;
long long pgpgout;
long long pswpin;
long long pswpout;
long long pgalloc_high;
long long pgalloc_normal;
long long pgalloc_dma;
long long pgfree;
long long pgactivate;
long long pgdeactivate;
long long pgfault;
long long pgmajfault;
long long pgrefill_high;
long long pgrefill_normal;
long long pgrefill_dma;
long long pgsteal_high;
long long pgsteal_normal;
long long pgsteal_dma;
long long pgscan_kswapd_high;
long long pgscan_kswapd_normal;
long long pgscan_kswapd_dma;
long long pgscan_direct_high;
long long pgscan_direct_normal;
long long pgscan_direct_dma;
long long pginodesteal;
long long slabs_scanned;
long long kswapd_steal;
long long kswapd_inodesteal;
long long pageoutrun;
long long allocstall;
long long pgrotated;
};



char *nfs_v2_names[18] = {
	"null", "getattr", "setattr", "root", "lookup", "readlink",
	"read", "wrcache", "write", "create", "remove", "rename",
	"link", "symlink", "mkdir", "rmdir", "readdir", "fsstat"};

char *nfs_v3_names[22] ={
	 "null", "getattr", "setattr", "lookup", "access", "readlink",
	 "read", "write", "create", "mkdir", "symlink", "mknod", 
	 "remove", "rmdir", "rename", "link", "readdir", "readdirplus",
	 "fsstat", "fsinfo", "pathconf", "commit"};

char *nfs_v4s_names[40] = {
	"op0-unused",   "op1-unused",   "op2-future",   "access",       "close",        "commit",      
	"create",       "delegpurge",   "delegreturn",  "getattr",      "getfh",        "link",        
	"lock",         "lockt",        "locku",        "lookup",       "lookup_root",  "nverify",     
	"open",         "openattr",     "open_conf",    "open_dgrd",    "putfh",        "putpubfh",    
	"putrootfh",    "read",         "readdir",      "readlink",     "remove",       "rename",      
	"renew",        "restorefh",    "savefh",       "secinfo",      "setattr",      "setcltid",    
	"setcltidconf", "verify",       "write",        "rellockowner" };

char *nfs_v4c_names[35] = {
	"null",         "read",         "write",        "commit",       "open",         "open_conf",   
	"open_noat",    "open_dgrd",    "close",        "setattr",      "fsinfo",       "renew",       
	"setclntid",    "confirm",      "lock",         "lockt",        "locku",        "access",      
	"getattr",      "lookup",       "lookup_root",  "remove",       "rename",       "link",        
	"symlink",      "create",       "pathconf",     "statfs",       "readlink",     "readdir",     
	"server_caps",  "delegreturn",  "getacl",       "setacl",       "fs_locations" };

int nfs_v2c_found=0;
int nfs_v2s_found=0;
int nfs_v3c_found=0;
int nfs_v3s_found=0;
int nfs_v4c_found=0;
int nfs_v4s_found=0;
int nfs_clear=0;

struct nfs_stat {
	long v2c[18];	/* verison 2 client */
	long v3c[22];	/* verison 3 client */
	long v4c[35];	/* verison 4 client */
	long v2s[18];	/* verison 2 server */
	long v3s[22];	/* verison 3 server */
	long v4s[40];	/* verison 4 server */
};

#define NETMAX 32
struct net_stat {
	unsigned long if_name[17];
	unsigned long long if_ibytes;
	unsigned long long if_obytes;
	unsigned long long if_ipackets;
	unsigned long long if_opackets;
	unsigned long if_ierrs;
	unsigned long if_oerrs;
	unsigned long if_idrop;   
	unsigned long if_ififo;   
	unsigned long if_iframe;   
	unsigned long if_odrop;   
	unsigned long if_ofifo;   
	unsigned long if_ocarrier;   
	unsigned long if_ocolls;   
} ;
#ifdef PARTITIONS
#define PARTMAX 256
struct part_stat {
	int part_major;
	int part_minor;
	unsigned long part_blocks;
	char part_name[16];
	unsigned long part_rio;
	unsigned long part_rmerge;
	unsigned long part_rsect;
	unsigned long part_ruse;
	unsigned long part_wio;
	unsigned long part_wmerge;
	unsigned long part_wsect;
	unsigned long part_wuse;
	unsigned long part_run;
	unsigned long part_use;
	unsigned long part_aveq;
};
#endif /*PARTITIONS*/


#ifdef POWER

/* XXXXXXX need to test if rewind() worked or not for lparcfg */
int lparcfg_reread=1;
/* Reset at end of each interval so LPAR cfg is only read once each interval
 * even if proc_lparcfg() is called multiple times
 * Note: lparcfg is not read via proc_read() !
 */
int lparcfg_processed=0;

struct {
char version_string[16];		/*lparcfg 1.3 */
int version;
char serial_number[16];			/*HAL,0210033EA*/
char system_type[16];			/*HAL,9124-720*/
int  partition_id;			/*11*/
/* 
R4=0x14
R5=0x0
R6=0x800b0000
R7=0x1000000040004
*/
int BoundThrds;				/*=1*/
int CapInc;				/*=1*/
long long DisWheRotPer;			/*=2070000*/
int MinEntCap;				/*=10*/
int MinEntCapPerVP;			/*=10*/
int MinMem;				/*=2048*/
int DesMem;				/*=4096*/
int MinProcs;				/*=1*/
int partition_max_entitled_capacity;	/*=400*/
int system_potential_processors;	/*=4*/
		/**/
int partition_entitled_capacity;	/*=20*/
int system_active_processors;		/*=4*/
int pool_capacity;			/*=4*/
int unallocated_capacity_weight;	/*=0*/
int capacity_weight;			/*=0*/
int capped;				/*=1*/
int unallocated_capacity;		/*=0*/
long long pool_idle_time;		/*=0*/
long long pool_idle_saved;
long long pool_idle_diff;
int pool_num_procs;			/*=0*/
long long purr;				/*=0*/
long long purr_saved;
long long purr_diff;
long long timebase;
int partition_active_processors;	/*=1*/
int partition_potential_processors;	/*=40*/
int shared_processor_mode;		/*=1*/
int smt_mode;				/* 1: off, 2: SMT-2, 4: SMT-4 */
int cmo_enabled;			/* 1 means AMS is Active */
int entitled_memory_pool_number; 	/*  pool number = 0 */
int entitled_memory_weight;		/* 0 to 255 */
long cmo_faults;			/* Hypervisor Page-in faults = big number */
long cmo_faults_save;			/* above saved */
long cmo_faults_diff;			/* delta */
long cmo_fault_time_usec;		/* Hypervisor time in micro seconds = big */
long cmo_fault_time_usec_save;		/* above saved */
long cmo_fault_time_usec_diff;		/* delta */
long backing_memory;		/* AIX pmem in bytes */
long cmo_page_size;		/* AMS page size in bytes */
long entitled_memory_pool_size;	/* AMS whole pool size in bytes */
long entitled_memory_loan_request;	/* AMS requesting more memory loaning */

#ifdef EXPERIMENTAL
/* new data in SLES11 for POWER 2.6.27 (may be a little earlier too) */
long DesEntCap;
long DesProcs;
long DesVarCapWt;
long DedDonMode;
long group;
long pool;
long entitled_memory;
long entitled_memory_group_number;
long unallocated_entitled_memory_weight;
long unallocated_io_mapping_entitlement;
/* new data in SLES11 for POWER 2.6.27 */
#endif /* EXPERIMENTAL */

} lparcfg;

int lpar_count=0;

#define LPAR_LINE_MAX   50
#define LPAR_LINE_WIDTH 80
char lpar_buffer[LPAR_LINE_MAX][LPAR_LINE_WIDTH];

int lpar_sanity=55;

char *locate(char *s)
{
int i;
int len;
	len=strlen(s);
	for(i=0;i<lpar_count;i++)
		if( !strncmp(s,lpar_buffer[i],len))
			return lpar_buffer[i];
	return "";
}

#define NUMBER_NOT_VALID -999

long long read_longlong(char *s)
{
long long x;
int ret;
int len;
int i;
char *str;
	str = locate(s);
	len=strlen(str);
	if(len == 0) {
		return NUMBER_NOT_VALID;
	}
	for(i=0;i<len;i++) {
		if(str[i] == '=') {
			ret = sscanf(&str[i+1], "%lld", &x);
			if(ret != 1) {
				fprintf(stderr,"sscanf for %s failed returned = %d line=%s\n", s, ret, str);
				return -1;
			}
/* fprintf(fp,"DEBUG read %s value %lld\n",s,x);*/
			return x;
		}
	}
	fprintf(stderr,"read_long_long failed returned line=%s\n", str);
	return -2;
}


/* Return of 0 means data not available */
int proc_lparcfg()
{
static FILE *fp = (FILE *)-1;
/* Only try to read /proc/ppc64/lparcfg once - remember if it's readable */
static int lparinfo_not_available=0;

char *str;
	/* If we already read and processed /proc/lparcfg in this interval - just return */
	if( lparcfg_processed == 1)
		return 1;

	if( lparinfo_not_available == 1)
		return 0;

	if( fp == (FILE *)-1) {
           if( (fp = fopen("/proc/ppc64/lparcfg","r")) == NULL) {
		error("failed to open - /proc/ppc64/lparcfg");
		fp = (FILE *)-1;
		lparinfo_not_available = 1;
		return 0;
	   }
	}

	for(lpar_count=0;lpar_count<LPAR_LINE_MAX-1;lpar_count++) {
		if(fgets(lpar_buffer[lpar_count],LPAR_LINE_WIDTH-1,fp) == NULL)
			break; 
	}
	if(lparcfg_reread) { /* XXXX  unclear is close open is necessary   - unfortunately this requires version on Linux on POWER install to test early releases */
		fclose(fp);
		fp = (FILE *)-1;
	} else rewind(fp);

	str=locate("lparcfg");  	sscanf(str, "lparcfg %s", lparcfg.version_string);
	str=locate("serial_number");	sscanf(str, "serial_number=%s", lparcfg.serial_number);
	str=locate("system_type");	sscanf(str, "system_type=%s", lparcfg.system_type);

#define GETDATA(variable) lparcfg.variable = read_longlong( __STRING(variable) );

	GETDATA(partition_id);
	GETDATA(BoundThrds);
	GETDATA(CapInc);
	GETDATA(DisWheRotPer);
	GETDATA(MinEntCap);
	GETDATA(MinEntCapPerVP);
	GETDATA(MinMem);
	GETDATA(DesMem);
	GETDATA(MinProcs);
	GETDATA(partition_max_entitled_capacity);
	GETDATA(system_potential_processors);
	GETDATA(partition_entitled_capacity);
	GETDATA(system_active_processors);
	GETDATA(pool_capacity);
	GETDATA(unallocated_capacity_weight);
	GETDATA(capacity_weight);
	GETDATA(capped);
	GETDATA(unallocated_capacity);
	lparcfg.pool_idle_saved = lparcfg.pool_idle_time;
	GETDATA(pool_idle_time);
	lparcfg.pool_idle_diff = lparcfg.pool_idle_time - lparcfg.pool_idle_saved;
	GETDATA(pool_num_procs);
	lparcfg.purr_saved = lparcfg.purr;
	GETDATA(purr);
	lparcfg.purr_diff = lparcfg.purr - lparcfg.purr_saved;
	GETDATA(partition_active_processors);
	GETDATA(partition_potential_processors);
	GETDATA(shared_processor_mode);
	/* Brute force, may provide temporary incorrect data during
	 * dynamic reconfiguraiton envents
	 */
	lparcfg.smt_mode=cpus / lparcfg.partition_active_processors;

	/* AMS additions */
	GETDATA(cmo_enabled);
	if( lparcfg.cmo_enabled == NUMBER_NOT_VALID )	{
		lparcfg.cmo_enabled = 0;
	}
	if( lparcfg.cmo_enabled ) {
		GETDATA(entitled_memory_pool_number); 	/*  pool number = 0 */
		GETDATA(entitled_memory_weight);	/* 0 to 255 */

		lparcfg.cmo_faults_save = lparcfg.cmo_faults;
		GETDATA(cmo_faults);			/* Hypervisor Page-in faults = big number */
		lparcfg.cmo_faults_diff = lparcfg.cmo_faults - lparcfg.cmo_faults_save;

		lparcfg.cmo_fault_time_usec_save = lparcfg.cmo_fault_time_usec;
		GETDATA(cmo_fault_time_usec);		/* Hypervisor time in micro seconds = big number */
		lparcfg.cmo_fault_time_usec_diff = lparcfg.cmo_fault_time_usec - lparcfg.cmo_fault_time_usec_save;

		GETDATA(backing_memory);		/* AIX pmem in bytes */
		GETDATA(cmo_page_size);			/* AMS page size in bytes */
		GETDATA(entitled_memory_pool_size);	/* AMS whole pool size in bytes */
		GETDATA(entitled_memory_loan_request);	/* AMS requesting more memory loaning */

	}
#ifdef EXPERIMENTAL
	GETDATA(DesEntCap);
	GETDATA(DesProcs);
	GETDATA(DesVarCapWt);
	GETDATA(DedDonMode);
	GETDATA(group);
	GETDATA(pool);
	GETDATA(entitled_memory);
	GETDATA(entitled_memory_group_number);
	GETDATA(unallocated_entitled_memory_weight);
	GETDATA(unallocated_io_mapping_entitlement);
#endif /* EXPERIMENTAL */

	lparcfg_processed=1;
	return 1;
}
#endif /*POWER*/


#define DISKMIN 256
#define DISKMAX diskmax
int diskmax = DISKMIN;

/* Supports up to 780, but not POWER6 595 follow-up with POWER7 */
/* XXXX needs rework to cope to with fairly rare but interesting higher numbers of CPU machines */
#define CPUMAX 256

struct data {
	struct dsk_stat *dk;
	struct cpu_stat cpu_total;
	struct cpu_stat cpuN[CPUMAX];
	struct mem_stat mem;
	struct vm_stat vm;
	struct nfs_stat nfs;
	struct net_stat ifnets[NETMAX];
#ifdef PARTITIONS
	struct part_stat parts[PARTMAX];
#endif /*PARTITIONS*/

	struct timeval tv;
	double time;
	struct procsinfo *procs;

	int    nprocs;
} database[2], *p, *q;


long long get_vm_value( char *s)	{
int currline;
int currchar;
long long result = -1;
char *check;
int len;
int found;

	for(currline=0; currline<proc[P_VMSTAT].lines; currline++) {
		len = strlen(s);
		for(currchar=0,found=1; currchar<len; currchar++) {
			if( proc[P_VMSTAT].line[currline][currchar] == 0 ||
			    s[currchar] != proc[P_VMSTAT].line[currline][currchar]) {
				found=0;
				break;
			}
		}
		if(found && proc[P_VMSTAT].line[currline][currchar] == ' ')	{
			result = strtoll(&proc[P_VMSTAT].line[currline][currchar+1],&check,10);
			if( *check == proc[P_VMSTAT].line[currline][currchar+1])	{
				fprintf(stderr,"%s has an unexpected format: >%s<\n", proc[P_VMSTAT].filename, proc[P_VMSTAT].line[currline]);
				return -1;
			}
			return result;
		}
	}
	return -1;
}

#define GETVM(variable) p->vm.variable = get_vm_value(__STRING(variable) );

int read_vmstat()
{
	proc_read(P_VMSTAT);
	if( proc[P_VMSTAT].read_this_interval == 0 || proc[P_VMSTAT].lines == 0)
		return(-1);

	/* Note: if the variable requested is not found in /proc/vmstat then it is set to -1 */
	GETVM(nr_dirty);
	GETVM(nr_writeback);
	GETVM(nr_unstable);
	GETVM(nr_page_table_pages);
	GETVM(nr_mapped);
	GETVM(nr_slab);
	GETVM(pgpgin);
	GETVM(pgpgout);
	GETVM(pswpin);
	GETVM(pswpout);
	GETVM(pgalloc_high);
	GETVM(pgalloc_normal);
	GETVM(pgalloc_dma);
	GETVM(pgfree);
	GETVM(pgactivate);
	GETVM(pgdeactivate);
	GETVM(pgfault);
	GETVM(pgmajfault);
	GETVM(pgrefill_high);
	GETVM(pgrefill_normal);
	GETVM(pgrefill_dma);
	GETVM(pgsteal_high);
	GETVM(pgsteal_normal);
	GETVM(pgsteal_dma);
	GETVM(pgscan_kswapd_high);
	GETVM(pgscan_kswapd_normal);
	GETVM(pgscan_kswapd_dma);
	GETVM(pgscan_direct_high);
	GETVM(pgscan_direct_normal);
	GETVM(pgscan_direct_dma);
	GETVM(pginodesteal);
	GETVM(slabs_scanned);
	GETVM(kswapd_steal);
	GETVM(kswapd_inodesteal);
	GETVM(pageoutrun);
	GETVM(allocstall);
	GETVM(pgrotated);
	return 1;
}


/* These macro simplify the access to the Main data structure */
#define DKDELTA(member) ( (q->dk[i].member > p->dk[i].member) ? 0 : (p->dk[i].member - q->dk[i].member))
#define SIDELTA(member) ( (q->si.member > p->si.member)       ? 0 : (p->si.member - q->si.member))

#define IFNAME 64

#define TIMEDELTA(member,index1,index2) ((p->procs[index1].member) - (q->procs[index2].member))
#define COUNTDELTA(member) ( (q->procs[topper[j].other].member > p->procs[i].member) ? 0 : (p->procs[i].member  - q->procs[topper[j].other].member) )

#define TIMED(member) ((double)(p->procs[i].member.tv_sec)) 

double *cpu_peak; /* ptr to array  - 1 for each cpu - 0 = average for machine */
double *disk_busy_peak;
double *disk_rate_peak;
double net_read_peak[NETMAX];
double net_write_peak[NETMAX];
int aiorunning;
int aiorunning_max = 0;
int aiocount;
int aiocount_max = 0;
float aiotime;
float aiotime_max =0.0;

char *dskgrp(int i)
{
static char error_string[] = { "Too-Many-Disks" };
static char *string[16] = {"",   "1",  "2",  "3", 
			   "4",  "5",  "6",  "7", 
			   "8",  "9",  "10", "11", 
			   "12", "13", "14", "15"};

	i = (int)((float)i/(float)disks_per_line);
	if(0 <= i && i <= 15 ) 
		return string[i];
	return error_string;
}

/* command checking against a list */

#define CMDMAX 64

char *cmdlist[CMDMAX];
int cmdfound = 0;

int cmdcheck(char *cmd)
{
	int i;
#ifdef CMDDEBUG
	fprintf(stderr,"cmdfound=%d\n",cmdfound);
	for(i=0;i<cmdfound;i++)
		fprintf(stderr,"cmdlist[%d]=\"%s\"\n",i,cmdlist[i]);
#endif /* CMDDEBUG */
	for(i=0;i<cmdfound;i++) {
		if(strlen(cmdlist[i]) == 0)
			continue;
		if( !strncmp(cmdlist[i],cmd,strlen(cmdlist[i])) )
			return 1;
	}
	return 0;
}

/* Convert secs + micro secs to a double */
double	doubletime(void)
{

	gettimeofday(&p->tv, 0);
	return((double)p->tv.tv_sec + p->tv.tv_usec * 1.0e-6);
}

void get_cpu_cnt()	{
	int i;

	/* Get CPU info from /proc/stat and populate proc[P_STAT] */
	proc_read(P_STAT);

	/* Start with index [1] as [0] contains overall CPU statistics */
	for(i=1; i<proc[P_STAT].lines; i++) {
            if(strncmp("cpu",proc[P_STAT].line[i],3) == 0)
                    cpus=i;
            else
                    break;
    }
}

int stat8 = 0; /* used to determine the number of variables on a line */


void proc_cpu()
{
int i;
int row;
static int intr_line = 0;
static int ctxt_line = 0;
static int btime_line= 0;
static int proc_line = 0;
static int run_line  = 0;
static int block_line= 0;
static int proc_cpu_first_time = 1;
long long user;
long long nice;
long long sys;
long long idle;
long long iowait;
long long hardirq;
long long softirq;
long long steal;

	/* Only read data once per interval */
	if( proc_cpu_done == 1)
		return;

	/* If number of CPUs changed, then we need to find the index of intr_line, ... again */
	if( old_cpus != cpus)
		intr_line = 0;

	if(proc_cpu_first_time) {
		stat8 = sscanf(&proc[P_STAT].line[0][5], "%lld %lld %lld %lld %lld %lld %lld %lld", 
			&user,
			&nice,
			&sys,
			&idle,
			&iowait,
			&hardirq,
			&softirq,
			&steal);
		proc_cpu_first_time = 0;
	}
	user = nice = sys = idle = iowait = hardirq = softirq = steal = 0;
	if(stat8 == 8) {
		sscanf(&proc[P_STAT].line[0][5], "%lld %lld %lld %lld %lld %lld %lld %lld", 
			&user,
			&nice,
			&sys,
			&idle,
			&iowait,
			&hardirq,
			&softirq,
			&steal);
	} else { /* stat 4 variables here as older Linux proc */
		sscanf(&proc[P_STAT].line[0][5], "%lld %lld %lld %lld", 
			&user,
			&nice,
			&sys,
			&idle);
	}
	p->cpu_total.user = user + nice;
	p->cpu_total.wait = iowait; /* in the case of 4 variables = 0 */
	p->cpu_total.sys  = sys;
	/* p->cpu_total.sys  = sys + hardirq + softirq + steal;*/
	p->cpu_total.idle = idle;
	
	p->cpu_total.irq     = hardirq;
	p->cpu_total.softirq = softirq;
	p->cpu_total.steal   = steal;
	p->cpu_total.nice    = nice;
#ifdef DEBUG
	if(debug)fprintf(stderr,"XX user=%lld wait=%lld sys=%lld idle=%lld\n",
			p->cpu_total.user,
			p->cpu_total.wait,
			p->cpu_total.sys,
			p->cpu_total.idle);
#endif /*DEBUG*/

	for(i=0;i<cpus;i++ ) {
	    user = nice = sys = idle = iowait = hardirq = softirq = steal = 0;

	    /* allow for large CPU numbers */
	    if(i+1 > 1000)     row = 8;
	    else if(i+1 > 100) row = 7;
	    else if(i+1 > 10)  row = 6;
	    else row = 5;

	    if(stat8 == 8) {
		sscanf(&proc[P_STAT].line[i+1][row], 
			"%lld %lld %lld %lld %lld %lld %lld %lld", 
		&user,
		&nice,
		&sys,
		&idle,
		&iowait,
		&hardirq,
		&softirq,
		&steal);
	    } else {
		sscanf(&proc[P_STAT].line[i+1][row], "%lld %lld %lld %lld", 
		&user,
		&nice,
		&sys,
		&idle);
	    }
		p->cpuN[i].user = user + nice;
		p->cpuN[i].wait = iowait;
		p->cpuN[i].sys  = sys;
		/*p->cpuN[i].sys  = sys + hardirq + softirq + steal;*/
		p->cpuN[i].idle = idle;

		p->cpuN[i].irq     = hardirq;
		p->cpuN[i].softirq = softirq;
		p->cpuN[i].steal   = steal;
		p->cpuN[i].nice    = nice;
	}

	if(intr_line == 0) {
		if(proc[P_STAT].line[i+1][0] == 'p' &&
		   proc[P_STAT].line[i+1][1] == 'a' &&
		   proc[P_STAT].line[i+1][2] == 'g' &&
		   proc[P_STAT].line[i+1][3] == 'e' ) {
			/* 2.4 kernel */
			intr_line = i+3;
			ctxt_line = i+5;
			btime_line= i+6;
			proc_line = i+7;
			run_line  = i+8;
			block_line= i+9;
		}else {
			/* 2.6 kernel */
			intr_line = i+1;
			ctxt_line = i+2;
			btime_line= i+3;
			proc_line = i+4;
			run_line  = i+5;
			block_line= i+6;
		}
	}
	p->cpu_total.intr = -1;
	p->cpu_total.ctxt = -1;
	p->cpu_total.btime = -1;
	p->cpu_total.procs = -1;
	p->cpu_total.running = -1;
	p->cpu_total.blocked = -1;
	if(proc[P_STAT].lines >= intr_line)
	sscanf(&proc[P_STAT].line[intr_line][0], "intr %lld", &p->cpu_total.intr);
	if(proc[P_STAT].lines >= ctxt_line)
	sscanf(&proc[P_STAT].line[ctxt_line][0], "ctxt %lld", &p->cpu_total.ctxt);
	if(proc[P_STAT].lines >= btime_line)
	sscanf(&proc[P_STAT].line[btime_line][0], "btime %lld", &p->cpu_total.btime);
	if(proc[P_STAT].lines >= proc_line)
	sscanf(&proc[P_STAT].line[proc_line][0], "processes %lld", &p->cpu_total.procs);
	if(proc[P_STAT].lines >= run_line)
	sscanf(&proc[P_STAT].line[run_line][0], "procs_running %lld", &p->cpu_total.running);
	if(proc[P_STAT].lines >= block_line)
	sscanf(&proc[P_STAT].line[block_line][0], "procs_blocked %lld", &p->cpu_total.blocked);

	/* If we had a change in the number of CPUs, copy current interval data to the previous, so we
	 * get a "0" utilization interval, but better than negative or 100%.
	 * Heads-up - This effects POWER SMT changes too.
	 */
	if( old_cpus != cpus )	{
		memcpy((void *) &(q->cpu_total), (void *) &(p->cpu_total), sizeof(struct cpu_stat));
		memcpy((void *) q->cpuN, (void *) p->cpuN, sizeof(struct cpu_stat) * cpus );
	}

	/* Flag that we processed /proc/stat data; re-set in proc_read() when we re-read /proc/stat */
	proc_cpu_done = 1;
}

void proc_nfs()
{
int i;
int j;
int len;

/* sample /proc/net/rpc/nfs
net 0 0 0 0
rpc 70137 0 0
proc2 18 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
proc3 22 0 27364 0 32 828 22 40668 0 1 0 0 0 0 0 0 0 0 1212 6 2 1 0
proc4 35 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
    if(proc[P_NFS].fp != 0) {
	/* client version 2 line readers "proc2 18 num num etc" */
	len=strlen(proc[P_NFS].line[2]);
	for(j=0,i=8;i<len && j<18;i++) {
		if(proc[P_NFS].line[2][i] == ' ') {
			p->nfs.v2c[j] =atol(&proc[P_NFS].line[2][i+1]);
			nfs_v2c_found=1;
			j++;
		}
	}
	/* client version 3 line readers "proc3 22 num num etc" */
	len=strlen(proc[P_NFS].line[3]);
	for(j=0,i=8;i<len && j<22;i++) {
		if(proc[P_NFS].line[3][i] == ' ') {
			p->nfs.v3c[j] =atol(&proc[P_NFS].line[3][i+1]);
			nfs_v3c_found=1;
			j++;
		}
	}
	/* client version 4 line readers "proc4 35 num num etc" */
	len=strlen(proc[P_NFS].line[4]);
	for(j=0,i=8;i<len && j<35;i++) {
		if(proc[P_NFS].line[4][i] == ' ') {
			p->nfs.v4c[j] =atol(&proc[P_NFS].line[4][i+1]);
			nfs_v4c_found=1;
			j++;
		}
	}
    }
/* sample /proc/net/rpc/nfsd 
rc 0 0 0
fh 0 0 0 0 0
io 0 0
th 4 0 0.000 0.000 0.000 0.000 0.000 0.000 0.000 0.000 0.000 0.000
ra 32 0 0 0 0 0 0 0 0 0 0 0
net 0 0 0 0
rpc 0 0 0 0 0
proc2 18 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
proc3 22 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
proc4 2 0 0
proc4ops 40 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
    if(proc[P_NFSD].fp != 0) {
	/* server version 2 line readers "proc2 18 num num etc" */
	len=strlen(proc[P_NFSD].line[7]);
	for(j=0,i=8;i<len && j<18;i++) {
		if(proc[P_NFSD].line[2][i] == ' ') {
			p->nfs.v2s[j] =atol(&proc[P_NFSD].line[7][i+1]);
			nfs_v2s_found=1;
			j++;
		}
	}
	/* server version 3 line readers "proc3 22 num num etc" */
	len=strlen(proc[P_NFSD].line[8]);
	for(j=0,i=8;i<len && j<22;i++) {
		if(proc[P_NFS].line[3][i] == ' ') {
			p->nfs.v3s[j] =atol(&proc[P_NFSD].line[8][i+1]);
			nfs_v3s_found=1;
			j++;
		}
	}
	/* server version 4 line readers "proc4ops 40 num num etc"  NOTE: the "ops" hence starting in column 11 */ 
	len=strlen(proc[P_NFSD].line[10]);
	for(j=0,i=11;i<len && j<40;i++) {
		if(proc[P_NFS].line[3][i] == ' ') {
			p->nfs.v4s[j] =atol(&proc[P_NFSD].line[10][i+1]);
			nfs_v4s_found=1;
			j++;
		}
	}
    }
}

void proc_kernel()
{
int i;
	p->cpu_total.uptime=0.0;
	p->cpu_total.idletime=0.0;
	p->cpu_total.uptime=atof(proc[P_UPTIME].line[0]);
	for(i=0;i<strlen(proc[P_UPTIME].line[0]);i++) {
		if(proc[P_UPTIME].line[0][i] == ' ') {
			p->cpu_total.idletime=atof(&proc[P_UPTIME].line[0][i+1]);
			break;
		}
	}

        sscanf(&proc[P_LOADAVG].line[0][0], "%f %f %f", 
		&p->cpu_total.mins1,
		&p->cpu_total.mins5,
		&p->cpu_total.mins15);

}

char *proc_find_sb(char * p)
{
	for(; *p != 0;p++)
		if(*p == ' ' && *(p+1) == '(')
			return p;
	return 0;
}

#define DISK_MODE_IO 1
#define DISK_MODE_DISKSTATS 2
#define DISK_MODE_PARTITIONS 3

int disk_mode = 0;

void proc_disk_io(double elapsed)
{
int diskline;
int i;
int ret;
char *str;
int fudged_busy;

	disks = 0;
	for(diskline=0;diskline<proc[P_STAT].lines;diskline++) {
		if(strncmp("disk_io", proc[P_STAT].line[diskline],7) == 0) 
			break;
	}
	for(i=8;i<strlen(proc[P_STAT].line[diskline]);i++) {
		if( proc[P_STAT].line[diskline][i] == ':')
			disks++;
	}

	str=&proc[P_STAT].line[diskline][0];
	for(i=0;i<disks;i++) {
		str=proc_find_sb(str);
		if(str == 0)
			break;
		ret = sscanf(str, " (%d,%d):(%ld,%ld,%ld,%ld,%ld", 
			&p->dk[i].dk_major,
			&p->dk[i].dk_minor,
			&p->dk[i].dk_noinfo,
			&p->dk[i].dk_reads,
			&p->dk[i].dk_rkb,
			&p->dk[i].dk_writes,
			&p->dk[i].dk_wkb);
		if(ret != 7)
			exit(7);
		p->dk[i].dk_xfers = p->dk[i].dk_noinfo;
		/* blocks  are 512 bytes*/
		p->dk[i].dk_rkb = p->dk[i].dk_rkb/2;
		p->dk[i].dk_wkb = p->dk[i].dk_wkb/2;

		p->dk[i].dk_bsize = (p->dk[i].dk_rkb+p->dk[i].dk_wkb)/p->dk[i].dk_xfers*1024;

		/* assume a disk does 200 op per second */
		fudged_busy = (p->dk[i].dk_reads + p->dk[i].dk_writes)/2;
		if(fudged_busy > 100*elapsed)
			p->dk[i].dk_time += 100*elapsed;
		p->dk[i].dk_time = fudged_busy;

		sprintf(p->dk[i].dk_name,"dev-%d-%d",p->dk[i].dk_major,p->dk[i].dk_minor);
/*	fprintf(stderr,"disk=%d name=\"%s\" major=%d minor=%d\n", i,p->dk[i].dk_name, p->dk[i].dk_major,p->dk[i].dk_minor); */
		str++;
	}
}

void proc_diskstats(double elapsed)
{
static FILE *fp = (FILE *)-1;
char buf[1024];
int i;
int ret;

	if( fp == (FILE *)-1) {
           if( (fp = fopen("/proc/diskstats","r")) == NULL) {
           /* DEBUG if( (fp = fopen("diskstats","r")) == NULL) { */
		error("failed to open - /proc/diskstats");
		disks=0;
		return;
	   }
	}
/*
   2    0 fd0 1 0 2 13491 0 0 0 0 0 13491 13491
   3    0 hda 41159 53633 1102978 620181 39342 67538 857108 4042631 0 289150 4668250
   3    1 hda1 58209 58218 0 0
   3    2 hda2 148 4794 10 20
   3    3 hda3 65 520 0 0
   3    4 hda4 35943 1036092 107136 857088
  22    0 hdc 167 5394 22308 32250 0 0 0 0 0 22671 32250 <-- USB !!
   8    0 sda 990 2325 4764 6860 9 3 12 417 0 6003 7277
   8    1 sda1 3264 4356 12 12
*/
	for(i=0;i<DISKMAX;) {
		if(fgets(buf,1024,fp) == NULL)
			break;
		/* zero the data ready for reading */
		p->dk[i].dk_major = 
		p->dk[i].dk_minor =
		p->dk[i].dk_name[0] =
		p->dk[i].dk_reads =
		p->dk[i].dk_rmerge =
		p->dk[i].dk_rkb =
		p->dk[i].dk_rmsec =
		p->dk[i].dk_writes =
		p->dk[i].dk_wmerge =
		p->dk[i].dk_wkb =
		p->dk[i].dk_wmsec =
		p->dk[i].dk_inflight =
		p->dk[i].dk_time =
		p->dk[i].dk_11 =0;

		ret = sscanf(&buf[0], "%d %d %s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
			&p->dk[i].dk_major,
			&p->dk[i].dk_minor,
			&p->dk[i].dk_name[0],
			&p->dk[i].dk_reads,
			&p->dk[i].dk_rmerge,
			&p->dk[i].dk_rkb,
			&p->dk[i].dk_rmsec,
			&p->dk[i].dk_writes,
			&p->dk[i].dk_wmerge,
			&p->dk[i].dk_wkb,
			&p->dk[i].dk_wmsec,
			&p->dk[i].dk_inflight,
			&p->dk[i].dk_time,
			&p->dk[i].dk_11 );
		if(ret == 7) { /* shuffle the data around due to missing columns for partitions */
			p->dk[i].dk_partition = 1;
			p->dk[i].dk_wkb = p->dk[i].dk_rmsec;
			p->dk[i].dk_writes = p->dk[i].dk_rkb;
			p->dk[i].dk_rkb = p->dk[i].dk_rmerge;
			p->dk[i].dk_rmsec=0;
			p->dk[i].dk_rmerge=0;
	
		}
		else if(ret == 14) p->dk[i].dk_partition = 0;
		else fprintf(stderr,"disk sscanf wanted 14 but returned=%d line=%s\n", 
	 			ret,buf);

		p->dk[i].dk_rkb /= 2; /* sectors = 512 bytes */
		p->dk[i].dk_wkb /= 2;
		p->dk[i].dk_xfers = p->dk[i].dk_reads + p->dk[i].dk_writes;
		if(p->dk[i].dk_xfers == 0)
			p->dk[i].dk_bsize = 0;
		else
			p->dk[i].dk_bsize = ((p->dk[i].dk_rkb+p->dk[i].dk_wkb)/p->dk[i].dk_xfers)*1024;

		p->dk[i].dk_time /= 10.0; /* in milli-seconds to make it upto 100%, 1000/100 = 10 */
	
		if( p->dk[i].dk_xfers > 0)
			i++;	
	}
	if(reread) {
		fclose(fp);
		fp = (FILE *)-1;
	} else rewind(fp);
	disks = i;
}

void strip_spaces(char *s)
{
char *p;
int spaced=1;

	p=s;
	for(p=s;*p!=0;p++) {
		if(*p == ':')
			*p=' ';
		if(*p != ' ') {
			*s=*p;
			s++;
			spaced=0;
		} else if(spaced) {
			/* do no thing as this is second space */
			} else {
				*s=*p;
				s++;
				spaced=1;
			}

	}
	*s = 0;
}

void proc_partitions(double elapsed)
{
static FILE *fp = (FILE *)-1;
char buf[1024];
int i = 0;
int ret;

	if( fp == (FILE *)-1) {
           if( (fp = fopen("/proc/partitions","r")) == NULL) {
		error("failed to open - /proc/partitions");
		partitions=0;
		return;
	   }
	}
	if(fgets(buf,1024,fp) == NULL) goto end; /* throw away the header lines */
	if(fgets(buf,1024,fp) == NULL) goto end;
/*
major minor  #blocks  name     rio rmerge rsect ruse wio wmerge wsect wuse running use aveq

  33     0    1052352 hde 2855 15 2890 4760 0 0 0 0 -4 7902400 11345292
  33     1    1050304 hde1 2850 0 2850 3930 0 0 0 0 0 3930 3930
   3     0   39070080 hda 9287 19942 226517 90620 8434 25707 235554 425790 -12 7954830 33997658
   3     1   31744408 hda1 651 90 5297 2030 0 0 0 0 0 2030 2030
   3     2    6138720 hda2 7808 19561 218922 79430 7299 20529 222872 241980 0 59950 321410
   3     3     771120 hda3 13 41 168 80 0 0 0 0 0 80 80
   3     4          1 hda4 0 0 0 0 0 0 0 0 0 0 0
   3     5     408208 hda5 812 241 2106 9040 1135 5178 12682 183810 0 11230 192850
*/
	for(i=0;i<DISKMAX;i++) {
		if(fgets(buf,1024,fp) == NULL)
			break;
		strip_spaces(buf);
		ret = sscanf(&buf[0], "%d %d %lu %s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
			&p->dk[i].dk_major,
			&p->dk[i].dk_minor,
			&p->dk[i].dk_blocks,
		(char *)&p->dk[i].dk_name,
			&p->dk[i].dk_reads,
			&p->dk[i].dk_rmerge,
			&p->dk[i].dk_rkb,
			&p->dk[i].dk_rmsec,
			&p->dk[i].dk_writes,
			&p->dk[i].dk_wmerge,
			&p->dk[i].dk_wkb,
			&p->dk[i].dk_wmsec,
			&p->dk[i].dk_inflight,
			&p->dk[i].dk_use,
			&p->dk[i].dk_aveq
			);
		p->dk[i].dk_rkb /= 2; /* sectors = 512 bytes */
		p->dk[i].dk_wkb /= 2;
		p->dk[i].dk_xfers = p->dk[i].dk_rkb + p->dk[i].dk_wkb;
		if(p->dk[i].dk_xfers == 0)
			p->dk[i].dk_bsize = 0;
		else
			p->dk[i].dk_bsize = (p->dk[i].dk_rkb+p->dk[i].dk_wkb)/p->dk[i].dk_xfers*1024;

		p->dk[i].dk_time /= 10.0; /* in milli-seconds to make it upto 100%, 1000/100 = 10 */
	
		if(ret != 15) {
#ifdef DEBUG
			if(debug)fprintf(stderr,"sscanf wanted 15 returned = %d line=%s\n", ret,buf);
#endif /*DEBUG*/
			partitions_short = 1;
		} else partitions_short = 0;
	}
	end:
	if(reread) {
		fclose(fp);
		fp = (FILE *)-1;
	} else rewind(fp);
	disks = i;
}

void proc_disk(double elapsed)
{
struct stat buf;
int ret;
	if(disk_mode == 0) {
		ret = stat("/proc/diskstats", &buf);
		if(ret == 0) {
			disk_mode=DISK_MODE_DISKSTATS;
		} else {
	               ret = stat("/proc/partitions", &buf);
			if(ret == 0) {
				disk_mode=DISK_MODE_PARTITIONS;
			} else {
				disk_mode=DISK_MODE_IO;
			}
		}
	}
	switch(disk_mode){
	case DISK_MODE_IO: 		proc_disk_io(elapsed);   break;
	case DISK_MODE_DISKSTATS: 	proc_diskstats(elapsed); break;
	case DISK_MODE_PARTITIONS: 	proc_partitions(elapsed); break;
	}
}
#undef isdigit
#define isdigit(ch) ( ( '0' <= (ch)  &&  (ch) >= '9')? 0: 1 )

long proc_mem_search( char *s)
{
int i;
int j;
int len;
	len=strlen(s);
	for(i=0;i<proc[P_MEMINFO].lines;i++ ) {
		if( !strncmp(s, proc[P_MEMINFO].line[i],len) ) {
			for(j=len;
				!isdigit(proc[P_MEMINFO].line[i][j]) &&
				proc[P_MEMINFO].line[i][j] != 0;
				j++)
				/* do nothing */ ;
			return atol( &proc[P_MEMINFO].line[i][j]);
		}
	}
	return -1;
}

void proc_mem()
{
	if( proc[P_MEMINFO].read_this_interval == 0)
		proc_read(P_MEMINFO);

	p->mem.memtotal   = proc_mem_search("MemTotal");
	p->mem.memfree    = proc_mem_search("MemFree");
	p->mem.memshared  = proc_mem_search("MemShared");
	p->mem.buffers    = proc_mem_search("Buffers");
	p->mem.cached     = proc_mem_search("Cached");
	p->mem.swapcached = proc_mem_search("SwapCached");
	p->mem.active     = proc_mem_search("Active");
	p->mem.inactive   = proc_mem_search("Inactive");
	p->mem.hightotal  = proc_mem_search("HighTotal");
	p->mem.highfree   = proc_mem_search("HighFree");
	p->mem.lowtotal   = proc_mem_search("LowTotal");
	p->mem.lowfree    = proc_mem_search("LowFree");
	p->mem.swaptotal  = proc_mem_search("SwapTotal");
	p->mem.swapfree   = proc_mem_search("SwapFree");
#ifdef LARGEMEM
	p->mem.dirty         = proc_mem_search("Dirty");
	p->mem.writeback     = proc_mem_search("Writeback");
	p->mem.mapped        = proc_mem_search("Mapped");
	p->mem.slab          = proc_mem_search("Slab");
	p->mem.committed_as  = proc_mem_search("Committed_AS");
	p->mem.pagetables    = proc_mem_search("PageTables");
	p->mem.hugetotal     = proc_mem_search("HugePages_Total");
	p->mem.hugefree      = proc_mem_search("HugePages_Free");
	p->mem.hugesize      = proc_mem_search("Hugepagesize");
#else
	p->mem.bigfree       = proc_mem_search("BigFree");
#endif /*LARGEMEM*/
}

#define MAX_SNAPS 72
#define MAX_SNAP_ROWS 20
#define SNAP_OFFSET 6

int next_cpu_snap = 0;
int cpu_snap_all = 0;

struct {
	double user;
	double kernel;
	double iowait;
	double idle;
} cpu_snap[MAX_SNAPS];

int snap_average()
{
int i;
int end;
int total = 0;

	if(cpu_snap_all)
		end = MAX_SNAPS;
	else
		end = next_cpu_snap;

	for(i=0;i<end;i++) {
		total = total + cpu_snap[i].user + cpu_snap[i].kernel;
	}
	return (total / end) ;
}

void snap_clear()
{
int i;
	for(i=0;i<MAX_SNAPS;i++) {
		cpu_snap[i].user = 0;
		cpu_snap[i].kernel = 0;
		cpu_snap[i].iowait = 0;
		cpu_snap[i].idle = 0;
	}
	next_cpu_snap=0;
	cpu_snap_all=0;
}

void plot_snap(WINDOW *pad)
{
int i;
int j;
	if (cursed) {
		mvwprintw(pad,0, 0, " CPU +-------------------------------------------------------------------------+");
		mvwprintw(pad,1, 0,"100%%-|");
		mvwprintw(pad,2, 1, "95%%-|");
		mvwprintw(pad,3, 1, "90%%-|");
		mvwprintw(pad,4, 1, "85%%-|");
		mvwprintw(pad,5, 1, "80%%-|");
		mvwprintw(pad,6, 1, "75%%-|");
		mvwprintw(pad,7, 1, "70%%-|");
		mvwprintw(pad,8, 1, "65%%-|");
		mvwprintw(pad,9, 1, "60%%-|");
		mvwprintw(pad,10, 1, "55%%-|");
		mvwprintw(pad,11, 1, "50%%-|");
		mvwprintw(pad,12, 1, "45%%-|");
		mvwprintw(pad,13, 1, "40%%-|");
		mvwprintw(pad,14, 1, "35%%-|");
		mvwprintw(pad,15, 1, "30%%-|");
		mvwprintw(pad,16, 1, "25%%-|");
		mvwprintw(pad,17, 1, "20%%-|");
		mvwprintw(pad,18, 1,"15%%-|");
		mvwprintw(pad,19, 1,"10%%-|");
		mvwprintw(pad,20, 1," 5%%-|");

 		if (colour){
 			mvwprintw(pad,21, 4, " +--------------------");
 			COLOUR wattrset(pad, COLOR_PAIR(2));
 			mvwprintw(pad,21, 26, "User%%");
 			COLOUR wattrset(pad, COLOR_PAIR(0));
 			mvwprintw(pad,21, 30, "---------");
 			COLOUR wattrset(pad, COLOR_PAIR(1));
 			mvwprintw(pad,21, 39, "System%%");
 			COLOUR wattrset(pad, COLOR_PAIR(0));
 			mvwprintw(pad,21, 45, "---------");
 			COLOUR wattrset(pad, COLOR_PAIR(4));
 			mvwprintw(pad,21, 54, "Wait%%");
 			COLOUR wattrset(pad, COLOR_PAIR(0));
 			mvwprintw(pad,21, 58, "---------------------+");
		} else {
			mvwprintw(pad,21, 4, " +-------------------------------------------------------------------------+");
		}

		for (j = 0; j < MAX_SNAPS; j++) {
			for (i = 0; i < MAX_SNAP_ROWS; i++) {
				wmove(pad,MAX_SNAP_ROWS-i, j+SNAP_OFFSET);
				if( (cpu_snap[j].user / 100 * MAX_SNAP_ROWS) > i+0.5) {
					COLOUR wattrset(pad,COLOR_PAIR(9));
					wprintw(pad,"U");
					COLOUR wattrset(pad,COLOR_PAIR(0));
				} else if( (cpu_snap[j].user + cpu_snap[j].kernel )/ 100 * MAX_SNAP_ROWS > i+0.5) {
					COLOUR wattrset(pad,COLOR_PAIR(8));
					wprintw(pad,"s");
					COLOUR wattrset(pad,COLOR_PAIR(0));
				} else if( (cpu_snap[j].user + cpu_snap[j].kernel +cpu_snap[j].iowait )/ 100 * MAX_SNAP_ROWS > i+0.5) {
					COLOUR wattrset(pad,COLOR_PAIR(10));
					wprintw(pad,"w");
					COLOUR wattrset(pad,COLOR_PAIR(0));
				} else 
					wprintw(pad," ");
			}
		}
		for (i = 0; i < MAX_SNAP_ROWS; i++) {
			wmove(pad,MAX_SNAP_ROWS-i, next_cpu_snap+SNAP_OFFSET);
			wprintw(pad,"|");
		}
		wmove(pad,MAX_SNAP_ROWS+1 - (snap_average() /5), next_cpu_snap+SNAP_OFFSET);
		wprintw(pad,"+");
		if(dotline) {
		    for (i = 0; i < MAX_SNAPS; i++) {
			wmove(pad,MAX_SNAP_ROWS+1-dotline*2, i+SNAP_OFFSET);
			wprintw(pad,"+");
		    }
		    dotline = 0;
		}
	}
}

/* This saves the CPU overall usage for later ploting on the screen */
void plot_save(double user, double kernel, double iowait, double idle)
{
	cpu_snap[next_cpu_snap].user = user;
	cpu_snap[next_cpu_snap].kernel = kernel;
	cpu_snap[next_cpu_snap].iowait = iowait;
	cpu_snap[next_cpu_snap].idle = idle;
	next_cpu_snap++;
	if(next_cpu_snap >= MAX_SNAPS) {
		next_cpu_snap=0;
		cpu_snap_all=1;
	}
}

/* This puts the CPU usage on the screen and draws the CPU graphs or outputs to the file */

void save_smp(WINDOW *pad, int cpu_no, int row, long user, long kernel, long iowait, long idle, long nice, long irq, long softirq, long steal)
{
static int firsttime = 1;
	if (cursed) {
		mvwprintw(pad,row,0, "%3d usr=%4ld sys=%4ld wait=%4ld idle=%4ld steal=%2ld nice=%4ld irq=%2ld sirq=%2ld\n",
		cpu_no, user, kernel, iowait, idle, steal, nice, irq, softirq, steal);
		return;
	}
	if(firsttime) {
		fprintf(fp,"CPUTICKS_ALL,AAA,user,sys,wait,idle,nice,irq,softirq,steal\n");
		fprintf(fp,"CPUTICKS%03d,AAA,user,sys,wait,idle,nice,irq,softirq,steal\n", cpu_no);
		firsttime=0;	
	}
	if(cpu_no==0) {
	fprintf(fp,"CPUTICKS_ALL,%s,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld\n", 
	        LOOP, user, kernel, iowait, idle, nice, irq, softirq, steal);
	} else {
	fprintf(fp,"CPUTICKS%03d,%s,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld\n",
	cpu_no, LOOP, user, kernel, iowait, idle, nice, irq, softirq, steal);
	}
}

void plot_smp(WINDOW *pad, int cpu_no, int row, double user, double kernel, double iowait, double idle)
{
	int	i;
	int	peak_col;

	if(show_rrd) return;

	if(cpu_peak[cpu_no] < (user + kernel + iowait) )
		cpu_peak[cpu_no] = (double)((int)user/2 + (int)kernel/2 + (int)iowait/2)*2.0;

	if (cursed) {
		if(cpu_no == 0)
			mvwprintw(pad,row, 0, "Avg");
		else
			mvwprintw(pad,row, 0, "%3d", cpu_no);
		mvwprintw(pad,row,  3, "% 6.1lf", user);
		mvwprintw(pad,row,  9, "% 6.1lf", kernel);
		mvwprintw(pad,row, 15, "% 6.1lf", iowait);
		mvwprintw(pad,row, 21, "% 6.1lf", idle);
		mvwprintw(pad,row, 27, "|");
		wmove(pad,row, 28);
		for (i = 0; i < (int)(user   / 2); i++){
			COLOUR wattrset(pad,COLOR_PAIR(9));
			wprintw(pad,"U");
			COLOUR wattrset(pad,COLOR_PAIR(0));
		}
		for (i = 0; i < (int)(kernel / 2); i++){
			COLOUR wattrset(pad,COLOR_PAIR(8));
			wprintw(pad,"s");
			COLOUR wattrset(pad,COLOR_PAIR(0));
		}
		for (i = 0; i < (int)(iowait / 2); i++) {
			COLOUR wattrset(pad,COLOR_PAIR(10));
			wprintw(pad,"W");
			COLOUR wattrset(pad,COLOR_PAIR(0));
		}
		for (i = 0; i < (int)(idle   / 2); i++)
			wprintw(pad," ");
		mvwprintw(pad,row, 77, "|");
		
		peak_col = 29 +(int)(cpu_peak[cpu_no]/2);
		if(peak_col > 77)
			peak_col=77;
		mvwprintw(pad,row, peak_col, ">");
	} else {
	/* Sanity check the numnbers */
		if( user < 0.0 || kernel < 0.0 || iowait < 0.0 || idle < 0.0 || idle >100.0) {
			user = kernel = iowait = idle = 0;
		}
		
		if(cpu_no == 0)
			fprintf(fp,"CPU_ALL,%s,%.1lf,%.1lf,%.1lf,%.1lf,,%d\n", LOOP,
			    user, kernel, iowait, idle,cpus);
		else {
			fprintf(fp,"CPU%03d,%s,%.1lf,%.1lf,%.1lf,%.1lf\n", cpu_no, LOOP,
			    user, kernel, iowait, idle);
		}
	}
}
/* Added variable to remember started children
 * 0 - start
 * 1 - snap
 * 2 - end
*/
#define CHLD_START 0
#define CHLD_SNAP 1
#define CHLD_END 2
int nmon_children[3] = {-1,-1,-1};

void init_pairs()
{
	COLOUR init_pair((short)0,(short)7,(short)0); /* White */
	COLOUR init_pair((short)1,(short)1,(short)0); /* Red */
	COLOUR init_pair((short)2,(short)2,(short)0); /* Green */
	COLOUR init_pair((short)3,(short)3,(short)0); /* Yellow */
	COLOUR init_pair((short)4,(short)4,(short)0); /* Blue */
	COLOUR init_pair((short)5,(short)5,(short)0); /* Magenta */
	COLOUR init_pair((short)6,(short)6,(short)0); /* Cyan */
	COLOUR init_pair((short)7,(short)7,(short)0); /* White */
	COLOUR init_pair((short)8,(short)0,(short)1); /* Red background, red text */
	COLOUR init_pair((short)9,(short)0,(short)2); /* Green background, green text */
	COLOUR init_pair((short)10,(short)0,(short)4); /* Blue background, blue text */
	COLOUR init_pair((short)11,(short)0,(short)3); /* Yellow background, yellow text */
	COLOUR init_pair((short)12,(short)0,(short)6); /* Cyan background, cyan text */
}

/* Signal handler 
 * SIGUSR1 or 2 is used to stop nmon cleanly
 * SIGWINCH is used when the window size is changed
 */
void	interrupt(int signum)
{
int child_pid;
int waitstatus;
	if (signum == SIGCHLD ) {
		while((child_pid = waitpid(0, &waitstatus, 0)) == -1 ) {
			if( errno == EINTR) /* retry */
				continue;
			return; /* ECHLD, EFAULT */
		}
                if(child_pid == nmon_children[CHLD_SNAP]) 
                	nmon_children[CHLD_SNAP] = -1;
		signal(SIGCHLD, interrupt);
		return;
	}
	if (signum == SIGUSR1 || signum == SIGUSR2) {
		maxloops = loop;
		return;
	}
	if (signum == SIGWINCH) {
		CURSE endwin(); /* stop + start curses so it works out the # of row and cols */
		CURSE initscr();
		CURSE cbreak();
		signal(SIGWINCH, interrupt);
		COLOUR colour = has_colors();
        	COLOUR start_color();
		COLOUR init_pairs();
		CURSE clear();
		return;
	}
	CURSE endwin();
	exit(0);
}


/* only place the q=previous and p=currect pointers are modified */
void switcher(void)
{
	static int	which = 1;
	int i;

	if (which) {
		p = &database[0];
		q = &database[1];
		which = 0;
	} else {
		p = &database[1];
		q = &database[0];
		which = 1;
	}
	if(flash_on)
		flash_on = 0;
	else
		flash_on = 1;

	/* Reset flags so /proc/... is re-read in next interval */
	for(i=0;i<P_NUMBER;i++) {
		proc[i].read_this_interval = 0;
	}
#ifdef POWER
	lparcfg_processed=0;
#endif
}


/* Lookup the right string */
char	*status(int n)
{
	switch (n) {
	case 0:
		return "Run  ";
	default:
		return "Sleep";
	}
}

/* Lookup the right process state string */
char	*get_state( char n)
{
	static char	duff[64];
	switch (n) {
	case 'R': return "Running  ";
	case 'S': return "Sleeping ";
	case 'D': return "DiskSleep";
	case 'Z': return "Zombie   ";
	case 'T': return "Traced   ";
	case 'W': return "Paging   ";
	default:
		sprintf(duff, "%d", n);
		return duff;
	}
}

#ifdef GETUSER
/* Convert User id (UID) to a name with caching for speed 
 * getpwuid() should be NFS/yellow pages safe
 */
char	*getuser(uid_t uid)
{
#define NAMESIZE 16
	struct user_info {
		uid_t uid;
		char	name[NAMESIZE];
	};
	static struct user_info *u = NULL;
	static int	used = 0;
	int	i;
	struct passwd *pw;

	i = 0;
	if (u != NULL) {
		for (i = 0; i < used; i++) {
			if (u[i].uid == uid) {
				return u[i].name;
			}
		}
		u = (struct user_info *)realloc(u, (sizeof(struct user_info ) * (i + 1)));
	} else
		u = (struct user_info *)malloc(sizeof(struct user_info ));
	used++;

	/* failed to find a match so add it */
	u[i].uid = uid;
	pw = getpwuid(uid);

	if (pw != NULL)
		strncpy(u[i].name, pw->pw_name, NAMESIZE);
	else
		sprintf(u[i].name, "unknown%d",uid);
	return u[i].name;
}
#endif /* GETUSER */

/* User Defined Disk Groups */

char   *save_word(char *in, char *out)
{
        int   len;
        int   i;
        len = strlen(in);
        out[0] = 0;
        for (i = 0; i < len; i++) {
                if ( isalnum(in[i]) || in[i] == '_' || in[i] == '-' || in[i] == '/' ) {
                        out[i] = in[i];
                        out[i+1] = 0;
                } else
                        break;
        }
        for (; i < len; i++)
                if (isalnum(in[i]))
                        return &in[i];
        return &in[i];
} 

#define DGROUPS 64
#define DGROUPITEMS 512

char   *dgroup_filename;
char   *dgroup_name[DGROUPS];
int   *dgroup_data;
int   dgroup_disks[DGROUPS];
int   dgroup_total_disks = 0;
int   dgroup_total_groups;

void load_dgroup(struct dsk_stat *dk)
{
	FILE * gp;
	char   line[4096];
	char   name[1024];
	int   i, j;
	char   *nextp;

	if (dgroup_loaded == 2)
		return;
	dgroup_data = MALLOC(sizeof(int)*DGROUPS * DGROUPITEMS);
	for (i = 0; i < DGROUPS; i++)
		for (j = 0; j < DGROUPITEMS; j++)
			dgroup_data[i*DGROUPITEMS+j] = -1;

	gp = fopen(dgroup_filename, "r");

	if (gp == NULL) {
		perror("opening disk group file");
		fprintf(stderr,"ERROR: failed to open %s\n", dgroup_filename);
		exit(9);
	}

	for (dgroup_total_groups = 0; 
		fgets(line, 4096-1, gp) != NULL && dgroup_total_groups < DGROUPS; 
		dgroup_total_groups++) {
		/* save the name */
		nextp = save_word(line, name);
		if(strlen(name) == 0) { /* was a blank line */
			fprintf(stderr,"ERROR nmon:ignoring odd line in diskgroup file \"%s\"\n",line);
			/* Decrement dgroup_total_groups by 1 to correct index for next loop */
			--dgroup_total_groups;
			continue;
		}
		/* Added +1 to be able to correctly store the terminating \0 character */
		dgroup_name[dgroup_total_groups] = MALLOC(strlen(name)+1);
		strcpy(dgroup_name[dgroup_total_groups], name);

		/* save the hdisks */
		for (i = 0; i < DGROUPITEMS && *nextp != 0; i++) {
			nextp = save_word(nextp, name);
			for (j = 0; j < disks; j++) {
				if ( strcmp(dk[j].dk_name, name) == 0 ) {
					/*DEBUG printf("DGadd group=%s,name=%s,disk=%s,dgroup_total_groups=%d,dgroup_total_disks=%d,j=%d,i=%d,index=%d.\n",
						dgroup_name[dgroup_total_groups], 
						name, dk[j].dk_name, dgroup_total_groups, dgroup_total_disks, j, i,dgroup_total_groups*DGROUPITEMS+i);
					*/
					dgroup_data[dgroup_total_groups*DGROUPITEMS+i] = j;
					dgroup_disks[dgroup_total_groups]++;
					dgroup_total_disks++;
					break;
				}
			}
			if (j == disks)
				fprintf(stderr,"ERROR nmon:diskgroup file - failed to find disk=%s for group=%s disks known=%d\n",
					 name, dgroup_name[dgroup_total_groups],disks);
		}
	}
	fclose(gp);
	dgroup_loaded = 2;
}


void list_dgroup(struct dsk_stat *dk)
{
	int   i, j, k, n;
	int   first = 1;

	/* DEBUG for (n = 0, i = 0; i < dgroup_total_groups; i++) {
		fprintf(fp, "CCCG,%03d,%s", n++, dgroup_name[i]);
		for (j = 0; j < dgroup_disks[i]; j++) {
			if (dgroup_data[i*DGROUPITEMS+j] != -1) {
				fprintf(fp, ",%d=%d", j, dgroup_data[i*DGROUPITEMS+j]);
			}
		}
		fprintf(fp, "\n");
	   }
	*/
	for (n = 0, i = 0; i < dgroup_total_groups; i++) {
		if (first) {
			fprintf(fp, "BBBG,%03d,User Defined Disk Groups Name,Disks\n", n++);
			first = 0;
		}
		fprintf(fp, "BBBG,%03d,%s", n++, dgroup_name[i]);
		for (k = 0, j = 0; j < dgroup_disks[i]; j++) {
			if (dgroup_data[i*DGROUPITEMS+j] != -1) {
				fprintf(fp, ",%s", dk[dgroup_data[i*DGROUPITEMS+j]].dk_name);
				k++;
			}
			/* add extra line if we have lots to stop spreadsheet line width problems */
			if (k == 128) {
				fprintf(fp, "\nBBBG,%03d,%s continued", n++, dgroup_name[i]);
			}
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "DGBUSY,Disk Group Busy %s", hostname);
	for (i = 0; i < DGROUPS; i++) {
		if (dgroup_name[i] != 0)
			fprintf(fp, ",%s", dgroup_name[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "DGREAD,Disk Group Read KB/s %s", hostname);
	for (i = 0; i < DGROUPS; i++) {
		if (dgroup_name[i] != 0)
			fprintf(fp, ",%s", dgroup_name[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "DGWRITE,Disk Group Write KB/s %s", hostname);
	for (i = 0; i < DGROUPS; i++) {
		if (dgroup_name[i] != 0)
			fprintf(fp, ",%s", dgroup_name[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "DGSIZE,Disk Group Block Size KB %s", hostname);
	for (i = 0; i < DGROUPS; i++) {
		if (dgroup_name[i] != 0)
			fprintf(fp, ",%s", dgroup_name[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "DGXFER,Disk Group Transfers/s %s", hostname);
	for (i = 0; i < DGROUPS; i++) {
		if (dgroup_name[i] != 0)
			fprintf(fp, ",%s", dgroup_name[i]);
	}
	fprintf(fp, "\n");

	/* If requested provide additional data available in /proc/diskstats */
	if( extended_disk == 1 && disk_mode == DISK_MODE_DISKSTATS )	{
		fprintf(fp, "DGREADS,Disk Group read/s %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGREADMERGE,Disk Group merged read/s %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGREADSERV,Disk Group read service time (SUM ms) %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGWRITES,Disk Group write/s %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGWRITEMERGE,Disk Group merged write/s %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGWRITESERV,Disk Group write service time (SUM ms) %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGINFLIGHT,Disk Group in flight IO %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
		fprintf(fp, "DGIOTIME,Disk Group time spent for IO (ms) %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
#ifdef EXPERIMENTAL
		fprintf(fp, "DGF11,Disk Group field 11 %s", hostname);
		for (i = 0; i < DGROUPS; i++) {
			if (dgroup_name[i] != 0)
				fprintf(fp, ",%s", dgroup_name[i]);
		}
		fprintf(fp, "\n");
#endif /*EXPERIMENTAL*/
	}
}



void hint(void)
{
	printf("\nHint: %s [-h] [-s <seconds>] [-c <count>] [-f -d <disks> -t -r <name>] [-x]\n\n", progname);
	printf("\t-h            FULL help information\n");
	printf("\tInteractive-Mode:\n");
	printf("\tread startup banner and type: \"h\" once it is running\n");
	printf("\tFor Data-Collect-Mode (-f)\n");
	printf("\t-f            spreadsheet output format [note: default -s300 -c288]\n");
	printf("\toptional\n");
	printf("\t-s <seconds>  between refreshing the screen [default 2]\n");
	printf("\t-c <number>   of refreshes [default millions]\n");
	printf("\t-d <disks>    to increase the number of disks [default 256]\n");
	printf("\t-t            spreadsheet includes top processes\n");
	printf("\t-x            capacity planning (15 min for 1 day = -fdt -s 900 -c 96)\n");
	printf("\n");
}

void help(void)
{
	hint();
	printf("Version - %s\n\n",SccsId);
	printf("For Interactive-Mode\n");
	printf("\t-s <seconds>  time between refreshing the screen [default 2]\n");
	printf("\t-c <number>   of refreshes [default millions]\n");
	printf("\t-g <filename> User Defined Disk Groups [hit g to show them]\n");
	printf("\t              - file = on each line: group_name <disks list> space separated\n");
	printf("\t              - like: database sdb sdc sdd sde\n");
	printf("\t              - upto 64 disk groups, 512 disks per line\n");
	printf("\t              - disks can appear more than once and in many groups\n");
	printf("\t-b            black and white [default is colour]\n");
	printf("\texample: %s -s 1 -c 100\n",progname);
	printf("\n");
	printf("For Data-Collect-Mode = spreadsheet format (comma separated values)\n");
	printf("\tNote: use only one of f,F,z,x or X and make it the first argument\n");
	printf("\t-f            spreadsheet output format [note: default -s300 -c288]\n");
	printf("\t\t\t output file is <hostname>_YYYYMMDD_HHMM.nmon\n");
	printf("\t-F <filename> same as -f but user supplied filename\n");
	printf("\t-r <runname>  used in the spreadsheet file [default hostname]\n");
	printf("\t-t            include top processes in the output\n");
	printf("\t-T            as -t plus saves command line arguments in UARG section\n");
	printf("\t-s <seconds>  between snap shots\n");
	printf("\t-c <number>   of snapshots before nmon stops\n");
	printf("\t-d <disks>    to increase the number of disks [default 256]\n");
	printf("\t-l <dpl>      disks/line default 150 to avoid spreadsheet issues. EMC=64.\n");
	printf("\t-g <filename> User Defined Disk Groups (see above) - see BBBG & DG lines\n");

	printf("\t-N            include NFS Network File System\n");
	printf("\t-I <percent>  Include process & disks busy threshold (default 0.1)\n");
	printf("\t              don't save or show proc/disk using less than this percent\n");
	printf("\t-m <directory> nmon changes to this directory before saving to file\n");
	printf("\texample: collect for 1 hour at 30 second intervals with top procs\n");
	printf("\t\t %s -f -t -r Test1 -s30 -c120\n",progname);
	printf("\n");
	printf("\tTo load into a spreadsheet:\n");
	printf("\tsort -A *nmon >stats.csv\n");
	printf("\ttransfer the stats.csv file to your PC\n");
	printf("\tStart spreadsheet & then Open type=comma-separated-value ASCII file\n");
	printf("\t The nmon analyser or consolidator does not need the file sorted.\n");
	printf("\n");
	printf("Capacity planning mode - use cron to run each day\n");
	printf("\t-x            sensible spreadsheet output for CP =  one day\n");
	printf("\t              every 15 mins for 1 day ( i.e. -ft -s 900 -c 96)\n");
	printf("\t-X            sensible spreadsheet output for CP = busy hour\n");
	printf("\t              every 30 secs for 1 hour ( i.e. -ft -s 30 -c 120)\n");
	printf("\n");

	printf("Interactive Mode Commands\n");
	printf("\tkey --- Toggles to control what is displayed ---\n");
	printf("\th   = Online help information\n");
	printf("\tr   = Machine type, machine name, cache details and OS version + LPAR\n");
	printf("\tc   = CPU by processor stats with bar graphs\n");
	printf("\tl   = long term CPU (over 75 snapshots) with bar graphs\n");
	printf("\tm   = Memory stats\n");
	printf("\tL   = Huge memory page stats\n");
	printf("\tV   = Virtual Memory and Swap stats\n");
	printf("\tk   = Kernel Internal stats\n"); 
	printf("\tn   = Network stats and errors\n");
	printf("\tN   = NFS Network File System\n");
	printf("\td   = Disk I/O Graphs\n");
	printf("\tD   = Disk I/O Stats\n");
	printf("\to   = Disk I/O Map (one character per disk showing how busy it is)\n");
	printf("\to   = User Defined Disk Groups\n");
	printf("\tj   = File Systems \n");
	printf("\tt   = Top Process stats use 1,3,4,5 to select the data & order\n");
	printf("\tu   = Top Process full command details\n");
	printf("\tv   = Verbose mode - tries to make recommendations\n");
#ifdef PARTITIONS
	printf("\tP   = Partitions Disk I/O Stats\n");
#endif 
#ifdef POWER
	printf("\tp   = Logical Partitions Stats\n");
#endif 
	printf("\tb   = black and white mode (or use -b option)\n");
	printf("\t.   = minimum mode i.e. only busy disks and processes\n");
	printf("\n");
	printf("\tkey --- Other Controls ---\n");
	printf("\t+   = double the screen refresh time\n");
	printf("\t-   = halves the screen refresh time\n");
	printf("\tq   = quit (also x, e or control-C)\n");
	printf("\t0   = reset peak counts to zero (peak = \">\")\n");
	printf("\tspace = refresh screen now\n");
	printf("\n");
	printf("Startup Control\n");
	printf("\tIf you find you always type the same toggles every time you start\n");
	printf("\tthen place them in the NMON shell variable. For example:\n");
	printf("\t export NMON=cmdrvtan\n");

	printf("\n");
	printf("Others:\n");
	printf("\ta) To you want to stop nmon - kill -USR2 <nmon-pid>\n");
	printf("\tb) Use -p and nmon outputs the background process pid\n");
	printf("\tc) To limit the processes nmon lists (online and to a file)\n");
	printf("\t   Either set NMONCMD0 to NMONCMD63 to the program names\n");
	printf("\t   or use -C cmd:cmd:cmd etc. example: -C ksh:vi:syncd\n");
	printf("\td) If you want to pipe nmon output to other commands use a FIFO:\n");
	printf("\t   mkfifo /tmp/mypipe\n");
	printf("\t   nmon -F /tmp/mypipe &\n");
	printf("\t   grep /tmp/mypipe\n");
	printf("\te) If nmon fails please report it with:\n");
	printf("\t   1) nmon version like: %s\n",VERSION);
	printf("\t   2) the output of cat /proc/cpuinfo\n");
	printf("\t   3) some clue of what you were doing\n");
	printf("\t   4) I may ask you to run the debug version\n");
	printf("\n");
	printf("\tDeveloper Nigel Griffiths\n");
	printf("\tFeedback welcome - on the current release only and state exactly the problem\n");
	printf("\tNo warranty given or implied.\n");
	exit(0);
}

#define JFSMAX 128
#define LOAD 1
#define UNLOAD 0
#define JFSNAMELEN 64
#define JFSTYPELEN 8

struct jfs {
	char name[JFSNAMELEN];
	char device[JFSNAMELEN];
	char type[JFSNAMELEN];
	int  fd;
	int  mounted;
	} jfs[JFSMAX];

int jfses =0;
void jfs_load(int load)
{
int i;
struct stat stat_buffer;
FILE * mfp; /* FILE pointer for mtab file*/
struct mntent *mp; /* mnt point stats */
static int jfs_loaded = 0;

	if(load==LOAD) { 
		if(jfs_loaded == 0) { 
			mfp = setmntent("/etc/mtab","r");
			for(i=0; i<JFSMAX && (mp = getmntent(mfp) ) != NULL; i++) {
				strncpy(jfs[i].device, mp->mnt_fsname,JFSNAMELEN);
				strncpy(jfs[i].name,mp->mnt_dir,JFSNAMELEN);
				strncpy(jfs[i].type, mp->mnt_type,JFSTYPELEN);
				mp->mnt_fsname[JFSNAMELEN-1]=0;
				mp->mnt_dir[JFSNAMELEN-1]=0;
				mp->mnt_type[JFSTYPELEN-1]=0;
			}
			endfsent();
			jfs_loaded = 1;
			jfses=i;
		}

		/* 1st or later time - just reopen the mount points */
		for(i=0;i<JFSMAX && jfs[i].name[0] !=0;i++) {
			if(stat(jfs[i].name, &stat_buffer) != -1 ) {

                                jfs[i].fd = open(jfs[i].name, O_RDONLY);
                                if(jfs[i].fd != -1 ) 
                                        jfs[i].mounted = 1;
                                else
                                        jfs[i].mounted = 0;
			}
			else jfs[i].mounted = 0;
		}
	} else { /* this is an unload request */
		if(jfs_loaded)
			for(i=0;i<JFSMAX && jfs[i].name[0] != 0;i++) {
			    if(jfs[i].mounted)
				close(jfs[i].fd);
			    jfs[i].fd=0;
			}
		else 
			/* do nothing */ ;
	}
}

/* We order this array rather than the actual process tables
 * the index is the position in the process table and
 * the time is the CPU used in the last period in seconds
 */
struct topper {
	int	index;
	int	other;
	double	size;
	double	io;
	int	time;
} *topper;
int	topper_size = 200;

/* Routine used by qsort to order the processes by CPU usage */
int	cpu_compare(const void *a, const void *b)
{
	return (int)(((struct topper *)b)->time - ((struct topper *)a)->time);
}

int	size_compare(const void *a, const void *b)
{
	return (int)((((struct topper *)b)->size - ((struct topper *)a)->size));
}

int	disk_compare(void *a, void *b)
{
	return (int)((((struct topper *)b)->io - ((struct topper *)a)->io));
}


/* checkinput is the subroutine to handle user input */
int checkinput(void)
{
	static int use_env = 1;
	char	buf[1024];
	int	bytes;
	int	chars;
	int	i;
	char *p;

	if (!cursed) /* not user input so stop with control-C */
		return 0;
	ioctl(fileno(stdin), FIONREAD, &bytes);

	if (bytes > 0 || use_env) {
		if(use_env) {
			use_env = 0;
			p=getenv("NMON");
			if(p!=0){
				strcpy(buf,p);
				chars = strlen(buf);
			}
			else chars = 0;
		}
		else
			chars = read(fileno(stdin), buf, bytes);
		if (chars > 0) {
			welcome = 0;
			for (i = 0; i < chars; i++) {
				switch (buf[i]) {
				case 'x':
				case 'q':
					nocbreak();
					endwin();
					exit(0);

				case '6':
				case '7':
				case '8':
				case '9':
					dotline = buf[i] - '0';
					break;
				case '+':
					seconds = seconds * 2;
					break;
				case '-':
					seconds = seconds / 2;
					if (seconds < 1)
						seconds = 1;
					break;
				case '.':
					if (show_all)
						show_all = 0;
					else {
						show_all = 1;
						show_disk = SHOW_DISK_STATS;
						show_top = 1;
						show_topmode =3;
					}
					clear();
					break;
				case '?':
				case 'h':
				case 'H':
					if (show_help)
						show_help = 0;
					else {
						show_help = 1;
						show_verbose = 0;
					}
					clear();
					break;
				case 'b':
				case 'B':
					FLIP(colour);
					clear();
					break;
				case 'Z':
					FLIP(show_raw);
					show_smp=1;
					clear();
					break;
				case 'l':
					FLIP (show_longterm);
					clear();
					break;
				case 'p':
					FLIP(show_lpar);
					clear();
					break;
				case 'V':
					FLIP(show_vm);
					clear();
					break;
				case 'j':
				case 'J':
					FLIP(show_jfs);
					jfs_load(show_jfs);
					clear();
					break;
#ifdef PARTITIONS
				case 'P':
					FLIP(show_partitions);
					clear();
					break;
#endif /*PARTITIONS*/
				case 'k':
				case 'K':
					FLIP(show_kernel);
					clear();
					break;
				case 'm':
				case 'M':
					FLIP(show_memory);
					clear();
					break;
				case 'L':
					FLIP(show_large);
					clear();
					break;
				case 'D':
					switch (show_disk) {
					case SHOW_DISK_NONE: 
						show_disk = SHOW_DISK_STATS; 
						break;
					case SHOW_DISK_STATS: 
						show_disk = SHOW_DISK_NONE; 
						break;
					case SHOW_DISK_GRAPH: 
						show_disk = SHOW_DISK_STATS; 
						break;
					}
					clear();
					break;
				case 'd':
					switch (show_disk) {
					case SHOW_DISK_NONE: 
						show_disk = SHOW_DISK_GRAPH; 
						break;
					case SHOW_DISK_STATS: 
						show_disk = SHOW_DISK_GRAPH; 
						break;
					case SHOW_DISK_GRAPH: 
						show_disk = 0; 
						break;
					}
					clear();
					break;
				case 'o':
				case 'O':
					FLIP(show_diskmap);
					clear();
					break;
				case 'n':
					if (show_net) {
						show_net = 0;
						show_neterror = 0;
					} else {
						show_net = 1;
						show_neterror = 3;
					}
					clear();
					break;
				case 'N':
					if(show_nfs == 0)
						show_nfs = 1;
					else if(show_nfs == 1)
						show_nfs = 2;
					else if(show_nfs == 2)
						show_nfs = 0;
					nfs_clear=1;
					clear();
					break;
				case 'c':
				case 'C':
					FLIP(show_smp);
					clear();
					break;
				case 'r':
				case 'R':
					FLIP(show_cpu);
					clear();
					break;
				case 't':
					show_topmode = 3; /* Fall Through */
				case 'T':
					FLIP(show_top);
					clear();
					break;
				case 'v':
					FLIP(show_verbose);
					clear();
					break;
				case 'u':
					if (show_args == ARGS_NONE) {
						args_load();
						show_args = ARGS_ONLY;
						show_top = 1;
						if( show_topmode != 3 &&
						 show_topmode != 4 &&
						 show_topmode != 5 )
						 show_topmode = 3;
					} else 
						show_args = ARGS_NONE;
					clear();
					break;
				case '1':
					show_topmode = 1;
					show_top = 1;
					clear();
					break;
/*
				case '2':
					show_topmode = 2;
					show_top = 1;
					clear();
					break;
*/
				case '3':
					show_topmode = 3;
					show_top = 1;
					clear();
					break;
				case '4':
					show_topmode = 4;
					show_top = 1;
					clear();
					break;
				case '5':
					show_topmode = 5;
					show_top = 1;
					clear();
					break;
				case '0':
					for(i=0;i<(max_cpus+1);i++)
						cpu_peak[i]=0;
					for(i=0;i<networks;i++) {
						net_read_peak[i]=0.0;
						net_write_peak[i]=0.0;
					}
					for(i=0;i<disks;i++) {
						disk_busy_peak[i]=0.0;
						disk_rate_peak[i]=0.0;
					}
					snap_clear();
					aiocount_max = 0;
					aiotime_max = 0.0;
					aiorunning_max = 0;
					huge_peak = 0;
					break;
				case ' ':
					clear();
					break;
				case 'g':
					FLIP(show_dgroup);
                                        clear();
                                        break;

				default: return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

void go_background(int def_loops, int def_secs)
{
	cursed = 0;
	if (maxloops == -1)
		maxloops = def_loops;
	if (seconds  == -1)
		seconds = def_secs;
	show_cpu     = 1;
	show_smp     = 1;
	show_disk    = SHOW_DISK_STATS;
	show_jfs     = 1;
	show_memory  = 1;
	show_large   = 1;
	show_kernel  = 1;
	show_net     = 1;
	show_all     = 1;
	show_top     = 0; /* top process */
	show_topmode = 3;
	show_partitions = 1;
	show_lpar = 1;
	show_vm   = 1;
}

void proc_net()
{
static FILE *fp = (FILE *)-1;
char buf[1024];
int i=0;
int ret;
unsigned long junk;

	if( fp == (FILE *)-1) {
           if( (fp = fopen("/proc/net/dev","r")) == NULL) {
		error("failed to open - /proc/net/dev");
		networks=0;
		return;
	   }
	}
	if(fgets(buf,1024,fp) == NULL) goto end; /* throw away the header lines */
	if(fgets(buf,1024,fp) == NULL) goto end; /* throw away the header lines */
/*
Inter-|   Receive                                                |  Transmit
 face |bytes    packets errs drop fifo frame compressed multicast|bytes    packets errs drop fifo colls carrier compressed
    lo:    1956      30    0    0    0     0          0         0     1956      30    0    0    0     0       0          0
  eth0:       0       0    0    0    0     0          0         0   458718       0  781    0    0     0     781          0
  sit0:       0       0    0    0    0     0          0         0        0       0    0    0    0     0       0          0
  eth1:       0       0    0    0    0     0          0         0        0       0    0    0    0     0       0          0
*/
	for(i=0;i<NETMAX;i++) {
		if(fgets(buf,1024,fp) == NULL)
			break;
		strip_spaces(buf);
				     /* 1   2   3    4   5   6   7   8   9   10   11   12  13  14  15  16 */
		ret = sscanf(&buf[0], "%s %llu %llu %lu %lu %lu %lu %lu %lu %llu %llu %lu %lu %lu %lu %lu",
		(char *)&p->ifnets[i].if_name,
			&p->ifnets[i].if_ibytes,
			&p->ifnets[i].if_ipackets,
			&p->ifnets[i].if_ierrs,
			&p->ifnets[i].if_idrop,
			&p->ifnets[i].if_ififo,
			&p->ifnets[i].if_iframe,
			&junk,
			&junk,
			&p->ifnets[i].if_obytes,
			&p->ifnets[i].if_opackets,
			&p->ifnets[i].if_oerrs,
			&p->ifnets[i].if_odrop,
			&p->ifnets[i].if_ofifo,
			&p->ifnets[i].if_ocolls,
			&p->ifnets[i].if_ocarrier
			);
		if(ret != 16) 
			fprintf(stderr,"sscanf wanted 16 returned = %d line=%s\n", ret, (char *)buf);
	}
	end:
	if(reread) {
		fclose(fp);
		fp = (FILE *)-1;
	} else rewind(fp);
	networks = i;
}


int proc_procsinfo(int pid, int index)
{
FILE *fp;
char filename[64];
char buf[1024*4];
int size=0;
int ret=0;
int count=0;

	sprintf(filename,"/proc/%d/stat",pid);
	if( (fp = fopen(filename,"r")) == NULL) {
		sprintf(buf,"failed to open file %s",filename);
		error(buf);
		return 0;
	}
	size = fread(buf, 1, 1024-1, fp);
	fclose(fp);
	if(size == -1) {
#ifdef DEBUG
		fprintf(stderr,"procsinfo read returned = %d assuming process stopped pid=%d\n", ret,pid);
#endif /*DEBUG*/
		return 0;
	}
        ret = sscanf(buf, "%d (%s)",
                &p->procs[index].pi_pid,
                &p->procs[index].pi_comm[0]);
	if(ret != 2) {
		fprintf(stderr,"procsinfo sscanf returned = %d line=%s\n", ret,buf);
		return 0;
	}
	p->procs[index].pi_comm[strlen(p->procs[index].pi_comm)-1] = 0;

	for(count=0; count<size;count++)	/* now look for ") " as dumb Infiniban driver includes "()" */
		if(buf[count] == ')' && buf[count+1] == ' ' ) break;

	if(count == size) {
#ifdef DEBUG
		fprintf(stderr,"procsinfo failed to find end of command buf=%s\n", buf);
#endif /*DEBUG*/
		return 0;
	}
	count++; count++;

        ret = sscanf(&buf[count],
#ifndef KERNEL_2_6_18
"%c %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %lu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d",
#else
"%c %d %d %d %d %d %lu %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %lu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d %d %lu %lu %llu",
#endif
                &p->procs[index].pi_state,
                &p->procs[index].pi_ppid,
                &p->procs[index].pi_pgrp,
                &p->procs[index].pi_session,
                &p->procs[index].pi_tty_nr,
                &p->procs[index].pi_tty_pgrp,
                &p->procs[index].pi_flags,
                &p->procs[index].pi_minflt,
                &p->procs[index].pi_cmin_flt,
                &p->procs[index].pi_majflt,
                &p->procs[index].pi_cmaj_flt,
                &p->procs[index].pi_utime,
                &p->procs[index].pi_stime,
                &p->procs[index].pi_cutime,
                &p->procs[index].pi_cstime,
                &p->procs[index].pi_pri,
                &p->procs[index].pi_nice,
#ifndef KERNEL_2_6_18
                &p->procs[index].junk,
#else
                &p->procs[index].pi_num_threads,
#endif
                &p->procs[index].pi_it_real_value,
                &p->procs[index].pi_start_time,
                &p->procs[index].pi_vsize,
                &p->procs[index].pi_rss,
                &p->procs[index].pi_rlim_cur,
                &p->procs[index].pi_start_code,
                &p->procs[index].pi_end_code,
                &p->procs[index].pi_start_stack,
                &p->procs[index].pi_esp,
                &p->procs[index].pi_eip,
                &p->procs[index].pi_pending_signal,
                &p->procs[index].pi_blocked_sig,
                &p->procs[index].pi_sigign,
                &p->procs[index].pi_sigcatch,
                &p->procs[index].pi_wchan,
                &p->procs[index].pi_nswap,
                &p->procs[index].pi_cnswap,
                &p->procs[index].pi_exit_signal,
                &p->procs[index].pi_cpu
#ifdef KERNEL_2_6_18
                ,
                &p->procs[index].pi_rt_priority,
                &p->procs[index].pi_policy,
                &p->procs[index].pi_delayacct_blkio_ticks
#endif

		);
#ifndef KERNEL_2_6_18
	if(ret != 37) {
		fprintf(stderr,"procsinfo2 sscanf wanted 37 returned = %d pid=%d line=%s\n", ret,pid,buf);
#else
	if(ret != 40) {
		fprintf(stderr,"procsinfo2 sscanf wanted 40 returned = %d pid=%d line=%s\n", ret,pid,buf);
#endif
		return 0;
	}

	sprintf(filename,"/proc/%d/statm",pid);
	if( (fp = fopen(filename,"r")) == NULL) {
		sprintf(buf,"failed to open file %s",filename);
		error(buf);
		return 0;
	}
	size = fread(buf, 1, 1024*4-1, fp);
	fclose(fp); /* close it even if the read failed, the file could have been removed 
			between open & read i.e. the device driver does not behave like a file */
	if(size == -1) {
		sprintf(buf,"failed to read file %s",filename);
		error(buf);
		return 0;
	}

        ret = sscanf(&buf[0], "%lu %lu %lu %lu %lu %lu %lu",
                &p->procs[index].statm_size,
                &p->procs[index].statm_resident,
                &p->procs[index].statm_share,
                &p->procs[index].statm_trs,
                &p->procs[index].statm_lrs,
                &p->procs[index].statm_drs,
                &p->procs[index].statm_dt
		);
	if(ret != 7) {
		fprintf(stderr,"sscanf wanted 7 returned = %d line=%s\n", ret,buf);
		return 0;
	}
	return 1;
}
#ifdef DEBUGPROC 
print_procs(int index)
{
printf("procs[%d].pid           =%d\n",index,procs[index].pi_pid);
printf("procs[%d].comm[0]       =%s\n",index,&procs[index].pi_comm[0]);
printf("procs[%d].state         =%c\n",index,procs[index].pi_state);
printf("procs[%d].ppid          =%d\n",index,procs[index].pi_ppid);
printf("procs[%d].pgrp          =%d\n",index,procs[index].pi_pgrp);
printf("procs[%d].session       =%d\n",index,procs[index].pi_session);
printf("procs[%d].tty_nr        =%d\n",index,procs[index].pi_tty_nr);
printf("procs[%d].tty_pgrp      =%d\n",index,procs[index].pi_tty_pgrp);
printf("procs[%d].flags         =%lu\n",index,procs[index].pi_flags);
printf("procs[%d].minflt       =%lu\n",index,procs[index].pi_minflt);
printf("procs[%d].cmin_flt     =%lu\n",index,procs[index].pi_cmin_flt);
printf("procs[%d].majflt       =%lu\n",index,procs[index].pi_majflt);
printf("procs[%d].cmaj_flt     =%lu\n",index,procs[index].pi_cmaj_flt);
printf("procs[%d].utime        =%lu\n",index,procs[index].pi_utime);
printf("procs[%d].stime        =%lu\n",index,procs[index].pi_stime);
printf("procs[%d].cutime       =%ld\n",index,procs[index].pi_cutime);
printf("procs[%d].cstime       =%ld\n",index,procs[index].pi_cstime);
printf("procs[%d].pri           =%d\n",index,procs[index].pi_pri);
printf("procs[%d].nice          =%d\n",index,procs[index].pi_nice);
#ifndef KERNEL_2_6_18
printf("procs[%d].junk          =%d\n",index,procs[index].junk);
#else
printf("procs[%d].num_threads   =%ld\n",index,procs[index].num_threads);
#endif
printf("procs[%d].it_real_value =%lu\n",index,procs[index].pi_it_real_value);
printf("procs[%d].start_time    =%lu\n",index,procs[index].pi_start_time);
printf("procs[%d].vsize         =%lu\n",index,procs[index].pi_vsize);
printf("procs[%d].rss           =%lu\n",index,procs[index].pi_rss);
printf("procs[%d].rlim_cur      =%lu\n",index,procs[index].pi_rlim_cur);
printf("procs[%d].start_code    =%lu\n",index,procs[index].pi_start_code);
printf("procs[%d].end_code      =%lu\n",index,procs[index].pi_end_code);
printf("procs[%d].start_stack   =%lu\n",index,procs[index].pi_start_stack);
printf("procs[%d].esp           =%lu\n",index,procs[index].pi_esp);
printf("procs[%d].eip           =%lu\n",index,procs[index].pi_eip);
printf("procs[%d].pending_signal=%lu\n",index,procs[index].pi_pending_signal);
printf("procs[%d].blocked_sig   =%lu\n",index,procs[index].pi_blocked_sig);
printf("procs[%d].sigign        =%lu\n",index,procs[index].pi_sigign);
printf("procs[%d].sigcatch      =%lu\n",index,procs[index].pi_sigcatch);
printf("procs[%d].wchan         =%lu\n",index,procs[index].pi_wchan);
printf("procs[%d].nswap         =%lu\n",index,procs[index].pi_nswap);
printf("procs[%d].cnswap        =%lu\n",index,procs[index].pi_cnswap);
printf("procs[%d].exit_signal   =%d\n",index,procs[index].pi_exit_signal);
printf("procs[%d].cpu           =%d\n",index,procs[index].pi_cpu);
#ifdef KERNEL_2_6_18
printf("procs[%d].rt_priority   =%lu\n",index,procs[index].pi_rt_priority);
printf("procs[%d].policy        =%lu\n",index,procs[index].pi_policy);
printf("procs[%d].delayacct_blkio_ticks=%llu\n",index,procs[index].pi_delayacct_blkio_ticks);
#endif
printf("OK\n");
}
#endif /*DEBUG*/
/* --- */

int isnumbers(char *s)
{
	while(*s != 0) {
		if( *s < '0' || *s > '9')
			return 0;
		s++;
	}
	return 1;
}

int getprocs(int details)
{
struct dirent *dent;
DIR *procdir;
int count =0;

	if((char *)(procdir = opendir("/proc")) == NULL) {
		printf("opendir(/proc) failed");
		return 0;
	}
	while( (char *)(dent = readdir(procdir)) != NULL ) {
		if(dent->d_type == 4) { /* is this a directlory */
/* mainframes report 0 = unknown every time !!!!  */
/*
		    printf("inode=%d type=%d name=%s\n",
				dent->d_ino,	
				dent->d_type,	
				dent->d_name);
*/
		    if(isnumbers(dent->d_name)) {
/*			printf("%s pid\n",dent->d_name); */
			if(details) {
				count=count+proc_procsinfo(atoi(dent->d_name),count);
			} else {
				count++;
			}
		    }
/*
		    else
			printf("NOT numbers\n");
*/
		}
	}
	closedir(procdir);
	return count;
}
/* --- */

char cpu_line[] = "---------------------------+-------------------------------------------------+";
/* Start process as specified in cmd in a child process without waiting
 * for completion
 * not sure if want to prevent this funcitonality for root user
 * when: CHLD_START, CHLD_SNAP or CHLD_END
 * cmd:  pointer to command string - assumed to be cleansed ....
 * timestamp_type: 0 - T%04d, 1 - detailed time stamp
 * loop: loop id (0 for CHLD_START)
 * the_time: time to use for timestamp generation
 */
void child_start(int when,
                char *cmd,
                int timestamp_type,
                int loop,
                time_t the_time)
{
        int i;
        pid_t child_pid;
        char time_stamp_str[20]="";
        char *when_info="";
        struct tm *tim; /* used to work out the hour/min/second */

#ifdef DEBUG2
fprintf(fp,"child start when=%d cmd=%s time=%d loop=%d\n",when,cmd,timestamp_type,loop);
#endif 
        /* Validate parameter and initialize error text */
        switch( when ) {
                case CHLD_START:
                        when_info = "nmon fork exec failure CHLD_START";
                        break;
                case CHLD_END:
                        when_info = "nmon fork exec failure CHLD_END";
                        break;

                case CHLD_SNAP:
                        /* check if old child has finished - otherwise we do nothing */
                        if( nmon_children[CHLD_SNAP] != -1 ) {
                                if(!cursed)fprintf(fp,"ERROR,T%04d, Starting snap command \"%s\" failed as previous child still running - killing it now\n", loop, cmd);
                                kill( nmon_children[CHLD_SNAP],9);
                        }

                        when_info = "nmon fork exec failure CHLD_SNAP";
                        break;
        }


        /* now fork off a child process. */
        switch (child_pid = fork()) {
                case -1:        /* fork failed. */
                        perror(when_info);
                        return;

                case 0:         /* inside child process.  */
                        /* create requested timestamp */
                        if( timestamp_type == 1 ) {
                                tim = localtime(&the_time);
                                sprintf(time_stamp_str,"%02d:%02d:%02d,%02d,%02d,%04d",
                                       tim->tm_hour, tim->tm_min, tim->tm_sec,
                                       tim->tm_mday, tim->tm_mon + 1, tim->tm_year + 1900);
                        }
                        else {
                                sprintf(time_stamp_str,"T%04d", loop);
                        }

                        /* close all open file pointers except the defaults */
                        for( i=3; i<5; ++i )
                                close(i);

                        /* Now switch to the defined command */
                        execlp(cmd, cmd, time_stamp_str,(void *)0);

                        /* If we get here the specified command could not be started */
                        perror(when_info);
                        exit(1);                     /* We can't do anything more */
                        /* never reached */

                default:        /* inside parent process. */
                        /* In father - remember child pid for future */
                        nmon_children[when] = child_pid;
        }
}

int main(int argc, char **argv)
{
	int secs;
	int cpu_idle;
	int cpu_user;
	int cpu_sys;
	int cpu_wait;
	int	n=0;			/* reusable counters */
	int	i=0;
	int	j=0;
	int	k=0;
	int	ret=0;
	int	max_sorted;
	int	skipped;
	int	x = 0;			/* curses row */
	int	y = 0;			/* curses column */
	double	elapsed;		/* actual seconds between screen updates */
	double	cpu_sum;
	double	cpu_busy;
	double	ftmp;
	int	top_first_time =1;
	int	disk_first_time =1;
	int	nfs_first_time =1;
	int	vm_first_time =1;
	int bbbr_line=0;
#ifdef POWER
	int	lpar_first_time =1;
#endif /* POWER */
	int	smp_first_time =1;
	int	proc_first_time =1;
	pid_t	firstproc = (pid_t)0;
	pid_t childpid = -1;
	int ralfmode = 0;
	char	pgrp[32];
	struct tm *tim; /* used to work out the hour/min/second */
	float	total_busy;	/* general totals */
	float	total_rbytes;	/* general totals */
	float	total_wbytes;
	float	total_xfers;
	struct utsname uts;		/* UNIX name, version, etc */
	double top_disk_busy = 0.0;
	char *top_disk_name = "";
	int disk_mb;
	double disk_total;
	double disk_busy;
	double disk_read;
	double disk_size;
	double disk_write;
	double disk_xfers;
	double total_disk_read;
	double total_disk_write;
	double total_disk_xfers;
	double readers;
	double writers;

	/* for popen on oslevel */
	char str[512];
	char * str_p;
	int varperftmp = 0;
	char *formatstring;
	char user_filename[512];
	char user_filename_set = 0;
	struct statfs statfs_buffer;
	float fs_size;
	float fs_bsize;
	float fs_free;
	float fs_size_used;
	char cmdstr[256];
	int disk_stats_read = 0;
	int updays, uphours, upmins;
	float v2c_total;
	float v2s_total;
	float v3c_total;
	float v3s_total;
	float v4c_total;
	float v4s_total;
	int room =1;
	int errors=0;
	WINDOW * padmem = NULL;
	WINDOW * padlarge = NULL;
	WINDOW * padpage = NULL;
	WINDOW * padker = NULL;
	WINDOW * padres = NULL;
	WINDOW * padnet = NULL;
	WINDOW * padneterr = NULL;
	WINDOW * padnfs = NULL;
	WINDOW * padcpu = NULL;
	WINDOW * padsmp = NULL;
	WINDOW * padlong = NULL;
	WINDOW * paddisk = NULL;
	WINDOW * paddg = NULL;
	WINDOW * padmap = NULL;
	WINDOW * padtop = NULL;
	WINDOW * padjfs = NULL;
	WINDOW * padlpar = NULL;
	WINDOW * padverb = NULL;
	WINDOW * padhelp = NULL;

        char  *nmon_start = (char *)NULL;
        char  *nmon_end   = (char *)NULL;
        char  *nmon_snap  = (char *)NULL;
        char  *nmon_tmp   = (char *)NULL;
        int   nmon_one_in  = 1;
        /* Flag what kind of time stamp we give to started children
         * 0: "T%04d"
         * 1: "hh:mm:ss,dd,mm,yyyy"
         */
        int   time_stamp_type =0;
        unsigned long  pagesize = 1024*4; /* Default page size is 4 KB but newer servers compiled with 64 KB pages */


#define MAXROWS 256
#define MAXCOLS 150 /* changed to allow maximum column widths */
#define BANNER(pad,string) {mvwhline(pad, 0, 0, ACS_HLINE,COLS-2); \
                                        wmove(pad,0,0); \
                                        wattron(pad,A_STANDOUT); \
                                        wprintw(pad," "); \
                                        wprintw(pad,string); \
                                        wprintw(pad," "); \
                                        wattroff(pad,A_STANDOUT); }

#define DISPLAY(pad,rows) { \
                        if(x+2+(rows)>LINES)\
                                pnoutrefresh(pad, 0,0,x,1,LINES-2,COLS-2); \
                        else \
                                pnoutrefresh(pad, 0,0,x,1,x+rows+1,COLS-2); \
                        x=x+(rows);     \
                        if(x+4>LINES) { \
                                room=0; \
                                mvwprintw(stdscr,LINES-1,10,"Warning: Some Statistics may not shown"); \
                        }               \
                       }

	/* check the user supplied options */
	progname = argv[0];
	for (i=(int)strlen(progname)-1;i>0;i--)
		if(progname[i] == '/') {
			progname = &progname[i+1];
		}

	if(getenv("NMONDEBUG") != NULL) 
		debug=1;
	if(getenv("NMONERROR") != NULL) 
		error_on=1;
	if(getenv("NMONBUG1") != NULL) 
		reread=1;
        if (getenv("NMONDEBUG") != NULL)
                debug = 1;

        if ((nmon_start = getenv("NMON_START")) != NULL) {
                nmon_start = check_call_string(nmon_start, "NMON_START");
        }

        if ((nmon_end = getenv("NMON_END")) != NULL) {
                nmon_end = check_call_string(nmon_end, "NMON_END");
        }

        if ((nmon_tmp = getenv("NMON_ONE_IN")) != NULL) {
                nmon_one_in = atoi(nmon_tmp);
                if( errno != 0 ) {
                        fprintf(stderr,"ERROR nmon: invalid NMON_ONE_IN shell variable\n");
                        nmon_one_in = 1;
                }
        }

        if ((nmon_snap = getenv("NMON_SNAP")) != NULL) {
                nmon_snap = check_call_string(nmon_snap, "NMON_SNAP");
        }

        if ((nmon_tmp = getenv("NMON_TIMESTAMP")) != NULL) {
                time_stamp_type = atoi(nmon_tmp);
                if (time_stamp_type != 0 && time_stamp_type != 1 )
                        time_stamp_type = 1;
        }
#ifdef DEBUG2
printf("NMON_START=%s.\n",nmon_start);
printf("NMON_END=%s.\n",nmon_end);
printf("NMON_SNAP=%s.\n",nmon_snap);
printf("ONE_IN=%d.\n",nmon_one_in);
printf("TIMESTAMP=%d.\n",time_stamp_type);
#endif 

#ifdef REREAD
		reread=1;
#endif
	for(i=0; i<CMDMAX;i++) {
		sprintf(cmdstr,"NMONCMD%d",i);
		cmdlist[i] = getenv(cmdstr);
		if(cmdlist[i] != 0) 
			cmdfound = i+1;
	}
	/* Setup long and short Hostname */
	gethostname(hostname, sizeof(hostname));
	strcpy(fullhostname, hostname);
	for (i = 0; i < sizeof(hostname); i++)
		if (hostname[i] == '.')
			hostname[i] = 0;
	if(run_name_set == 0)
		strcpy(run_name,hostname);

	/* Check the version of OS */
	uname(&uts);
	if(sysconf(_SC_PAGESIZE) > 1024*4) /* Check if we have the large 64 KB memory page sizes compiled in to the kernel */
		pagesize = sysconf(_SC_PAGESIZE);
	proc_init();

	while ( -1 != (i = getopt(argc, argv, "?Rhs:bc:Dd:fF:r:tTxXzeEl:qpC:Vg:Nm:I:Z" ))) {
		switch (i) {
		case '?':
			hint();
			exit(0);
		case 'h':
			help();
			break;
		case 's':
			seconds = atoi(optarg);
			break;
		case 'p':
			ralfmode = 1;
			break;
		case 'b':
			colour = 0;
			break;
		case 'c':
			maxloops = atoi(optarg);
			break;
		case 'N':
			show_nfs = 1;
			break;
		case 'm':
			if(chdir(optarg) == -1) {
				perror("changing directory failed");
				printf("Directory attempted was:%s\n",optarg);
				exit(993);
			}
			break;
		case 'I':
			ignore_procdisk_threshold = atof(optarg);
			break;
		case 'd':
			diskmax = atoi(optarg);
			if(diskmax < DISKMIN) {
				printf("nmon: ignoring -d %d option as the minimum is %d\n", diskmax, DISKMIN);
				diskmax = DISKMIN;
			}
			break;
		case 'D':
			extended_disk=1;
			break;
		case 'R':
			show_rrd = 1;
			go_background(288, 300);
			show_aaa = 0;
			show_para = 0;
			show_headings = 0;
			break;
		case 'r': strcpy(run_name,optarg); 
			run_name_set++;
			break;
		case 'F': /* background mode with user supplied filename */
			strcpy(user_filename,optarg);
			user_filename_set++;
			go_background(288, 300);
			break;

		case 'f': /* background mode i.e. for spread sheet output */
			go_background(288, 300);
			break;
		case 'T':
			show_args = ARGS_ONLY; /* drop through */
		case 't':
			show_top     = 1; /* put top process output in spreadsheet mode */
			show_topmode = 3;
			break;
		case 'z': /* background mode for 1 day output to /var/perf/tmp */
			varperftmp++;
			go_background(4*24, 15*60);
			break;

		case 'x': /* background mode for 1 day capacity planning */
			go_background(4*24, 15*60);
			show_top =1;
			show_topmode = 3;
			break;
		case 'X': /* background mode for 1 hour capacity planning */
			go_background(120, 30);
			show_top =1;
			show_topmode = 3;
			break;
		case 'Z':
			show_raw=1;
			break;
		case 'l':
			disks_per_line = atoi(optarg);
			if(disks_per_line < 3 || disks_per_line >250) disks_per_line = 100;
			break;
		case 'C': /* commandlist argument */
			cmdlist[0] = malloc(strlen(optarg)+1); /* create buffer */
			strcpy(cmdlist[0],optarg);
			if(cmdlist[0][0]!= 0)
				cmdfound=1;
			for(i=0,j=1;cmdlist[0][i] != 0;i++) {
				if(cmdlist[0][i] == ':') {
					cmdlist[0][i] = 0;
					cmdlist[j] = &cmdlist[0][i+1];
					j++;
					cmdfound=j;
					if(j >= CMDMAX) break;
				}
			}
			break;
		case 'V': /* nmon version */
			printf("nmon verion %s\n",VERSION);
			exit(0);
			break;
                case 'g': /* disk groups */
                        show_dgroup = 1;
                        dgroup_loaded = 1;
                        dgroup_filename = optarg;
                        break;
		}
	}
	/* Set parameters if not set by above */
	if (maxloops == -1)
		maxloops = 9999999;
	if (seconds  == -1)
		seconds = 2;
        if (cursed)
                show_dgroup = 0;

	/* -D need -g filename */
	if(extended_disk == 1 && show_dgroup == 0) {
		printf("nmon: ignoring -D (extended disk stats) as -g filename is missing\n");
		extended_disk=0;	
	}
	/* To get the pointers setup */
	switcher();

	/* Initialise the time stamps for the first loop */
	p->time = doubletime();
	q->time = doubletime();

	find_release();

	/* Determine number of active LOGICAL cpu - depends on SMT mode ! */
	get_cpu_cnt();
	max_cpus=old_cpus=cpus;

	proc_read(P_STAT);
	proc_cpu();
	proc_read(P_UPTIME);
	proc_read(P_LOADAVG);
	proc_kernel();
	memcpy(&q->cpu_total, &p->cpu_total, sizeof(struct cpu_stat));

	p->dk = malloc(sizeof(struct dsk_stat) * diskmax+1);	
	q->dk = malloc(sizeof(struct dsk_stat) * diskmax+1);	
	disk_busy_peak = malloc(sizeof(double) * diskmax);
	disk_rate_peak = malloc(sizeof(double) * diskmax);
	for(i=0;i<diskmax;i++) {
		disk_busy_peak[i]=0.0;
		disk_rate_peak[i]=0.0;
	}

	cpu_peak = malloc(sizeof(double) * (CPUMAX + 1)); /* MAGIC */
	for(i=0;i < max_cpus+1;i++)
		cpu_peak[i]=0.0;

	n = getprocs(0);
	p->procs = malloc(sizeof(struct procsinfo ) * n  +8);
	q->procs = malloc(sizeof(struct procsinfo ) * n  +8);
	p->nprocs = q->nprocs = n;

	/* Initialise the top processes table */
	topper = malloc(sizeof(struct topper ) * topper_size); /* round up */

	/* Get Disk Stats. */
	proc_disk(0.0);
	memcpy(q->dk, p->dk, sizeof(struct dsk_stat) * disks);

        /* load dgroup - if required */
        if (dgroup_loaded == 1) {
                load_dgroup(p->dk);
        }

	/* Get Network Stats. */
	proc_net();
	memcpy(q->ifnets, p->ifnets, sizeof(struct net_stat) * networks);
	for(i=0;i<networks;i++) {
		net_read_peak[i]=0.0;
		net_write_peak[i]=0.0;
	}

	/* If we are running in spreadsheet mode initialize all other data sets as well
	 * so we do not get incorrect data for the first reported interval
	 */
	if( !cursed)	{
		/* Get VM Stats */
		read_vmstat();

		/* Get Memory info */
		proc_mem();

#ifdef POWER
		/* Get LPAR Stats */
		proc_lparcfg();
#endif
	}
	/* Set the pointer ready for the next round */
	switcher();

	/* Initialise signal handlers so we can tidy up curses on exit */
	signal(SIGUSR1, interrupt);
	signal(SIGUSR2, interrupt);
	signal(SIGINT, interrupt);
	signal(SIGWINCH, interrupt);
	signal(SIGCHLD, interrupt);

	/* Start Curses */
	if (cursed) {
		initscr();
		cbreak();
		move(0, 0);
		refresh();
		COLOUR colour = has_colors();
        	COLOUR start_color();
                COLOUR init_pairs();
		clear();
		padlpar = newpad(11,MAXCOLS);
		padmap = newpad(24,MAXCOLS);
		padhelp = newpad(24,MAXCOLS);
		padmem = newpad(20,MAXCOLS);
		padlarge = newpad(20,MAXCOLS);
		padpage = newpad(20,MAXCOLS);
		padcpu = newpad(20,MAXCOLS);
		padsmp = newpad(MAXROWS,MAXCOLS);
		padlong = newpad(MAXROWS,MAXCOLS);
		padnet = newpad(MAXROWS,MAXCOLS);
		padneterr = newpad(MAXROWS,MAXCOLS);
		paddisk = newpad(MAXROWS,MAXCOLS);
		paddg = newpad(MAXROWS,MAXCOLS);
		padjfs = newpad(MAXROWS,MAXCOLS);
		padker = newpad(5,MAXCOLS);
		padverb = newpad(8,MAXCOLS);
		padres = newpad(23,MAXCOLS);
		padnfs = newpad(25,MAXCOLS);
		padtop = newpad(MAXROWS,MAXCOLS*2);


	} else {
		/* Output the header lines for the spread sheet */
		timer = time(0);
		tim = localtime(&timer);
		tim->tm_year += 1900 - 2000;  /* read localtime() manual page!! */
		tim->tm_mon  += 1; /* because it is 0 to 11 */
		if(varperftmp)
			sprintf( str, "/var/perf/tmp/%s_%02d.nmon", hostname, tim->tm_mday);
		else if(user_filename_set)
			strcpy( str, user_filename);
		else
			sprintf( str, "%s_%02d%02d%02d_%02d%02d.nmon",
			hostname,
			tim->tm_year,
			tim->tm_mon,
			tim->tm_mday, 
			tim->tm_hour, 
			tim->tm_min);
		if((fp = fopen(str,"w")) ==0 ) {
			perror("nmon: failed to open output file");
			printf("nmon: output filename=%s\n",str);
			exit(42);
		}
		/* disconnect from terminal */
		fflush(NULL);
		if (!debug && (childpid = fork()) != 0) {
			if(ralfmode)
				printf("%d\n",childpid);
			exit(0); /* parent returns OK */
		}
		if(!debug) {
			close(0);
			close(1);
			close(2);
			setpgrp(); /* become process group leader */
			signal(SIGHUP, SIG_IGN); /* ignore hangups */
		}
                /* Do the nmon_start activity early on */
                if (nmon_start) {
                        timer = time(0);
                        child_start(CHLD_START, nmon_start, time_stamp_type, 1, timer);
                }

		if(show_aaa) {
		fprintf(fp,"AAA,progname,%s\n", progname);
		fprintf(fp,"AAA,command,");
		for(i=0;i<argc;i++)
			fprintf(fp,"%s ",argv[i]);
		fprintf(fp,"\n");
		fprintf(fp,"AAA,version,%s\n", VERSION);
		fprintf(fp,"AAA,disks_per_line,%d\n", disks_per_line);
		fprintf(fp,"AAA,max_disks,%d,set by -d option\n", diskmax);
		fprintf(fp,"AAA,disks,%d,\n", disks);

		fprintf(fp,"AAA,host,%s\n", hostname);
		fprintf(fp,"AAA,user,%s\n", getenv("USER"));
		fprintf(fp,"AAA,OS,Linux,%s,%s,%s\n",uts.release,uts.version,uts.machine); 
		fprintf(fp,"AAA,runname,%s\n", run_name);
		fprintf(fp,"AAA,time,%02d:%02d.%02d\n", tim->tm_hour, tim->tm_min, tim->tm_sec);
		fprintf(fp,"AAA,date,%02d-%3s-%02d\n", tim->tm_mday, month[tim->tm_mon-1], tim->tm_year+2000);
		fprintf(fp,"AAA,interval,%d\n", seconds);
		fprintf(fp,"AAA,snapshots,%d\n", maxloops);
#ifdef POWER
		fprintf(fp,"AAA,cpus,%d,%d\n", cpus/lparcfg.smt_mode,cpus);	/* physical CPU, logical CPU */
		fprintf(fp,"AAA,CPU ID length,3\n");	/* Give analyzer a chance to easily find length of CPU number - 3 digits here! */
#else
		fprintf(fp,"AAA,cpus,%d\n", cpus);
#endif
		fprintf(fp,"AAA,proc_stat_variables,%d\n", stat8);

		fprintf(fp,"AAA,note0, Warning - use the UNIX sort command to order this file before loading into a spreadsheet\n");
		fprintf(fp,"AAA,note1, The First Column is simply to get the output sorted in the right order\n");
		fprintf(fp,"AAA,note2, The T0001-T9999 column is a snapshot number. To work out the actual time; see the ZZZ section at the end\n");
		}
		fflush(NULL);

		for (i = 1; i <= cpus; i++)
			fprintf(fp,"CPU%03d,CPU %d %s,User%%,Sys%%,Wait%%,Idle%%\n", i, i, run_name);
		fprintf(fp,"CPU_ALL,CPU Total %s,User%%,Sys%%,Wait%%,Idle%%,Busy,CPUs\n", run_name);
		fprintf(fp,"MEM,Memory MB %s,memtotal,hightotal,lowtotal,swaptotal,memfree,highfree,lowfree,swapfree,memshared,cached,active,bigfree,buffers,swapcached,inactive\n", run_name);

#ifdef POWER
		proc_lparcfg();
		if(lparcfg.cmo_enabled)
			fprintf(fp,"MEMAMS,AMS %s,Poolid,Weight,Hypervisor-Page-in/s,HypervisorTime(seconds),not_available_1,not_available_2,not_available_3,Physical-Memory(MB),Page-Size(KB),Pool-Size(MB),Loan-Request(KB)\n", run_name);

#ifdef EXPERIMENTAL
			fprintf(fp,"MEMEXPERIMENTAL,New lparcfg numbers %s,DesEntCap,DesProcs,DesVarCapWt,DedDonMode,group,pool,entitled_memory,entitled_memory_group_number,unallocated_entitled_memory_weight,unallocated_io_mapping_entitlement\n", run_name);
#endif /* EXPERIMENTAL */
#endif /* POWER */

		fprintf(fp,"PROC,Processes %s,Runnable,Blocked,pswitch,syscall,read,write,fork,exec,sem,msg\n", run_name);
/*
		fprintf(fp,"PAGE,Paging %s,faults,pgin,pgout,pgsin,pgsout,reclaims,scans,cycles\n", run_name);
		fprintf(fp,"FILE,File I/O %s,iget,namei,dirblk,readch,writech,ttyrawch,ttycanch,ttyoutch\n", run_name);
*/


		fprintf(fp,"NET,Network I/O %s,", run_name);
		for (i = 0; i < networks; i++)
			fprintf(fp,"%-2s-read-KB/s,", (char *)p->ifnets[i].if_name);
		for (i = 0; i < networks; i++)
			fprintf(fp,"%-2s-write-KB/s,", (char *)p->ifnets[i].if_name);
		fprintf(fp,"\n");
		fprintf(fp,"NETPACKET,Network Packets %s,", run_name);
		for (i = 0; i < networks; i++)
			fprintf(fp,"%-2s-read/s,", (char *)p->ifnets[i].if_name);
		for (i = 0; i < networks; i++)
			fprintf(fp,"%-2s-write/s,", (char *)p->ifnets[i].if_name);
		/* iremoved as it is not below in the BUSY line fprintf(fp,"\n"); */
#ifdef DEBUG
		if(debug)printf("disks=%d x%sx\n",(char *)disks,p->dk[0].dk_name);
#endif /*DEBUG*/
		for (i = 0; i < disks; i++)  {
			if(NEWDISKGROUP(i))
			    fprintf(fp,"\nDISKBUSY%s,Disk %%Busy %s", dskgrp(i) ,run_name);
			fprintf(fp,",%s", (char *)p->dk[i].dk_name);
		}
		for (i = 0; i < disks; i++) {
			if(NEWDISKGROUP(i))
			    fprintf(fp,"\nDISKREAD%s,Disk Read KB/s %s", dskgrp(i),run_name);
			fprintf(fp,",%s", (char *)p->dk[i].dk_name);
		}
		for (i = 0; i < disks; i++) {
			if(NEWDISKGROUP(i))
			    fprintf(fp,"\nDISKWRITE%s,Disk Write KB/s %s", (char *)dskgrp(i),run_name);
			fprintf(fp,",%s", (char *)p->dk[i].dk_name);
		}
		for (i = 0; i < disks; i++) {
			if(NEWDISKGROUP(i))
				fprintf(fp,"\nDISKXFER%s,Disk transfers per second %s", (char *)dskgrp(i),run_name);
			fprintf(fp,",%s", p->dk[i].dk_name);
		}
		for (i = 0; i < disks; i++) {
			if(NEWDISKGROUP(i))
				fprintf(fp,"\nDISKBSIZE%s,Disk Block Size %s", dskgrp(i),run_name);
			fprintf(fp,",%s", (char *)p->dk[i].dk_name);
		}
		if( extended_disk == 1 && disk_mode == DISK_MODE_DISKSTATS )    {
			for (i = 0; i < disks; i++) {
				if(NEWDISKGROUP(i))
					fprintf(fp,"\nDISKREADS%s,Disk Rd/s %s", dskgrp(i),run_name);
				fprintf(fp,",%s", (char *)p->dk[i].dk_name);
				}
			for (i = 0; i < disks; i++) {
				if(NEWDISKGROUP(i))
					fprintf(fp,"\nDISKWRITES%s,Disk Wrt/s %s", dskgrp(i),run_name);
				fprintf(fp,",%s", (char *)p->dk[i].dk_name);
			}
		}

		fprintf(fp,"\n");
                list_dgroup(p->dk);
		jfs_load(LOAD);
		fprintf(fp,"JFSFILE,JFS Filespace %%Used %s", hostname);
		for (k = 0; k < jfses; k++) {
  		    if(jfs[k].mounted && strncmp(jfs[k].name,"/proc",5)
  		    			&& strncmp(jfs[k].name,"/sys",4)
  		    			&& strncmp(jfs[k].name,"/dev/pts",8)
					&& strncmp(jfs[k].name,"/dev/shm",8)
					&& strncmp(jfs[k].name,"/var/lib/nfs/rpc",16)
			)  /* /proc gives invalid/insane values */
			fprintf(fp,",%s", jfs[k].name); 
		}
		fprintf(fp,"\n");
		jfs_load(UNLOAD);
#ifdef POWER
		if( proc_lparcfg() && lparcfg.shared_processor_mode != 0 ){
			fprintf(fp,"LPAR,Shared CPU LPAR Stats %s,PhysicalCPU,capped,shared_processor_mode,system_potential_processors,system_active_processors,pool_capacity,MinEntCap,partition_entitled_capacity,partition_max_entitled_capacity,MinProcs,Logical CPU,partition_active_processors,partition_potential_processors,capacity_weight,unallocated_capacity_weight,BoundThrds,MinMem,unallocated_capacity,pool_idle_time\n",hostname);

		}
#endif /*POWER*/
		if(show_top){
			fprintf(fp,"TOP,%%CPU Utilisation\n");
#ifndef KERNEL_2_6_18
			fprintf(fp,"TOP,+PID,Time,%%CPU,%%Usr,%%Sys,Size,ResSet,ResText,ResData,ShdLib,MinorFault,MajorFault,Command\n");
#else
			fprintf(fp,"TOP,+PID,Time,%%CPU,%%Usr,%%Sys,Size,ResSet,ResText,ResData,ShdLib,MinorFault,MajorFault,Command,Threads,IOwaitTime\n");
#endif
		}
		linux_bbbp("/etc/release",    "/bin/cat /etc/*ease 2>/dev/null", WARNING);
		linux_bbbp("lsb_release",    "/usr/bin/lsb_release -a 2>/dev/null", WARNING);
		linux_bbbp("fdisk-l",          "/sbin/fdisk -l 2>/dev/null", WARNING);
		linux_bbbp("/proc/cpuinfo",    "/bin/cat /proc/cpuinfo 2>/dev/null", WARNING);
		linux_bbbp("/proc/meminfo",    "/bin/cat /proc/meminfo 2>/dev/null", WARNING);
		linux_bbbp("/proc/stat",       "/bin/cat /proc/stat 2>/dev/null", WARNING);
		linux_bbbp("/proc/version",    "/bin/cat /proc/version 2>/dev/null", WARNING);
		linux_bbbp("/proc/net/dev",    "/bin/cat /proc/net/dev 2>/dev/null", WARNING);
#ifdef POWER
		linux_bbbp("ppc64_utils - lscfg",   	"/usr/sbin/lscfg 2>/dev/null", WARNING);
		linux_bbbp("ppc64_utils - ls-vdev",   	"/usr/sbin/ls-vdev 2>/dev/null", WARNING);
		linux_bbbp("ppc64_utils - ls-veth",   	"/usr/sbin/ls-veth 2>/dev/null", WARNING);
		linux_bbbp("ppc64_utils - ls-vscsi",   	"/usr/sbin/ls-vscsi 2>/dev/null", WARNING);
		linux_bbbp("ppc64_utils - lsmcode",   	"/usr/sbin/lsmcode 2>/dev/null", WARNING);
#endif
		linux_bbbp("/proc/diskinfo",   "/bin/cat /proc/diskinfo 2>/dev/null", WARNING);
		linux_bbbp("/proc/diskstats",   "/bin/cat /proc/diskstats 2>/dev/null", WARNING);

		linux_bbbp("/sbin/multipath",   "/sbin/multipath -l 2>/dev/null", WARNING);
		linux_bbbp("/dev/mapper",   	"ls -l /dev/mapper 2>/dev/null", WARNING);
		linux_bbbp("/dev/mpath",   		"ls -l /dev/mpath 2>/dev/null", WARNING);
		linux_bbbp("/dev/dm-*",   		"ls -l /dev/dm-* 2>/dev/null", WARNING);
		linux_bbbp("/dev/md*",   		"ls -l /dev/md* 2>/dev/null", WARNING);
		linux_bbbp("/dev/sd*",   		"ls -l /dev/sd* 2>/dev/null", WARNING);
		linux_bbbp("/proc/partitions", "/bin/cat /proc/partitions 2>/dev/null", WARNING);
		linux_bbbp("/proc/1/stat",     "/bin/cat /proc/1/stat 2>/dev/null", WARNING);
#ifndef KERNEL_2_6_18
		linux_bbbp("/proc/1/statm",    "/bin/cat /proc/1/statm 2>/dev/null", WARNING);
#endif
#ifdef POWER
		linux_bbbp("/proc/ppc64/lparcfg",    "/bin/cat /proc/ppc64/lparcfg 2>/dev/null", WARNING);
#endif
#ifdef MAINFRAME
		linux_bbbp("/proc/sysinfo",    "/bin/cat /proc/sysinfo 2>/dev/null", WARNING);
#endif
		linux_bbbp("/proc/net/rpc/nfs",        "/bin/cat /proc/net/rpc/nfs 2>/dev/null", WARNING);
		linux_bbbp("/proc/net/rpc/nfsd",        "/bin/cat /proc/net/rpc/nfsd 2>/dev/null", WARNING);
		linux_bbbp("ifconfig",        "/sbin/ifconfig 2>/dev/null", WARNING);
		linux_bbbp("/bin/df-m",        "/bin/df -m 2>/dev/null", WARNING);
		linux_bbbp("/bin/mount",        "/bin/mount 2>/dev/null", WARNING);
		linux_bbbp("/etc/fstab",    "/bin/cat /etc/fstab 2>/dev/null", WARNING);
		linux_bbbp("netstat -r",    "/bin/netstat -r 2>/dev/null", WARNING);
		linux_bbbp("uptime",    "/usr/bin/uptime  2>/dev/null", WARNING);
		linux_bbbp("getconf PAGESIZE",    "/usr/bin/getconf PAGESIZE  2>/dev/null", WARNING);

		sleep(1); /* to get the first stats to cover this one second and avoids divide by zero issues */
	     }
	/* To get the pointers setup */
	/* Was already done earlier, DONT'T switch back here to the old pointer! - switcher(); */
	checkinput();
	fflush(NULL);
#ifdef POWER 
lparcfg.timebase = -1; 
#endif

	/* Main loop of the code */
	for(loop=1; ; loop++) {
		/* Save the time and work out how long we were actually asleep
		 * Do this as early as possible and close to reading the CPU statistics in /proc/stat
		 */
		p->time = doubletime();
		elapsed = p->time - q->time;
		timer = time(0);
		tim = localtime(&timer);

		/* Get current count of CPU
		 * As side effect /proc/stat is read
		 */
		old_cpus = cpus;
		get_cpu_cnt();
#ifdef POWER
		/* Always get lpar info as well so we can report physical CPU usage
		 * to make data more meaningful. Return value is ignored here, but
		 * remembered in proc_lparcfg() !
		 */
		proc_lparcfg();
#endif

		disk_stats_read = 0;

		if(loop <= 3) /* This stops the nmon causing the cpu peak at startup */
			for(i=0;i < max_cpus+1;i++)
				cpu_peak[i]=0.0;
			
		/* Reset the cursor position to top left */
		y = x = 0;

		if (cursed) { /* Top line */
				box(stdscr,0,0);
				mvprintw(x, 1, "nmon"); 
				mvprintw(x, 6, "%s", VERSION); 
				if(flash_on) mvprintw(x,15,"[H for help]");
				mvprintw(x, 30, "Hostname=%s", hostname);
				mvprintw(x, 52, "Refresh=%2.0fsecs ", elapsed);
                                mvprintw(x, 70, "%02d:%02d.%02d",
				    tim->tm_hour, tim->tm_min, tim->tm_sec);
				wnoutrefresh(stdscr);
			x = x + 1;

			if(welcome && getenv("NMON") == 0) {

					COLOUR attrset(COLOR_PAIR(2));
mvprintw(x+1, 3, "------------------------------");
mvprintw(x+2, 3, "#    #  #    #   ####   #    #");
mvprintw(x+3, 3, "##   #  ##  ##  #    #  ##   #");
mvprintw(x+4, 3, "# #  #  # ## #  #    #  # #  #");
mvprintw(x+5, 3, "#  # #  #    #  #    #  #  # #");
mvprintw(x+6, 3, "#   ##  #    #  #    #  #   ##");
mvprintw(x+7, 3, "#    #  #    #   ####   #    #");
mvprintw(x+8, 3, "------------------------------");
					COLOUR attrset(COLOR_PAIR(0));
mvprintw(x+1, 40, "For help type H or ...");
mvprintw(x+2, 40, " nmon -?  - hint");
mvprintw(x+3, 40, " nmon -h  - full");
mvprintw(x+5, 40, "To start the same way every time");
mvprintw(x+6, 40, " set the NMON ksh variable");

mvprintw(x+10, 3, "Use these keys to toggle statistics on/off:");
mvprintw(x+11, 3, "   c = CPU        l = CPU Long-term   - = Faster screen updates");
mvprintw(x+12, 3, "   m = Memory     j = Filesystems     + = Slower screen updates");
mvprintw(x+13, 3, "   d = Disks      n = Network         V = Virtual Memory");
mvprintw(x+14, 3, "   r = Resource   N = NFS             v = Verbose hints");
mvprintw(x+15, 3, "   k = kernel     t = Top-processes   . = only busy disks/procs");
mvprintw(x+16, 3, "   h = more options                   q = Quit");
				x = x + 17;
			}
		} else {
			if (!cursed && nmon_snap && (loop % nmon_one_in) == 0 ) {
				child_start(CHLD_SNAP, nmon_snap, time_stamp_type, loop, timer);
			}


			if(!show_rrd)
			    fprintf(fp,"ZZZZ,%s,%02d:%02d:%02d,%02d-%s-%4d\n", LOOP, 
					tim->tm_hour, tim->tm_min, tim->tm_sec,
					tim->tm_mday, month[tim->tm_mon], tim->tm_year+1900);
			fflush(NULL);
		}
		if (show_verbose && cursed) {
			BANNER(padverb, "Verbose Mode");
			mvwprintw(padverb,1, 0, " Code    Resource            Stats   Now\tWarn\tDanger ");
		/*	DISPLAY(padverb,7); */
			/* move(x,0); */
			x=x+6;
		}
		if (show_help && cursed) {
			BANNER(padhelp, "HELP");
			mvwprintw(padhelp, 1, 5, "key  --- statistics which toggle on/off ---");
			mvwprintw(padhelp, 2, 5, "h = This help information");
			mvwprintw(padhelp, 3, 5, "r = RS6000/pSeries CPU/cache/OS/kernel/hostname details + LPAR");
			mvwprintw(padhelp, 4, 5, "t = Top Process Stats 1=basic 3=CPU");
			mvwprintw(padhelp, 5, 5, "    u = shows command arguments (hit twice to refresh)");
			mvwprintw(padhelp, 6, 5, "c = CPU by processor             l = longer term CPU averages");
			mvwprintw(padhelp, 7, 5, "m = Memory & Swap stats L=Huge   j = JFS Usage Stats");
			mvwprintw(padhelp, 8, 5, "n = Network stats                N = NFS");
			mvwprintw(padhelp, 9, 5, "d = Disk I/O Graphs D=Stats      o = Disks %%Busy Map");
			mvwprintw(padhelp,10, 5, "k = Kernel stats & loadavg       V = Virtual Memory");
			mvwprintw(padhelp,11, 5, "g = User Defined Disk Groups [start nmon with -g <filename>]");
			mvwprintw(padhelp,12, 5, "v = Verbose Simple Checks - OK/Warnings/Danger");
			mvwprintw(padhelp,13, 5, "b = black & white mode");
			mvwprintw(padhelp,14, 5, "--- controls ---");
			mvwprintw(padhelp,15, 5, "+ and - = double or half the screen refresh time");
			mvwprintw(padhelp,16, 5, "q = quit                     space = refresh screen now");
			mvwprintw(padhelp,17, 5, ". = Minimum Mode =display only busy disks and processes");
			mvwprintw(padhelp,18, 5, "0 = reset peak counts to zero (peak = \">\")");
			mvwprintw(padhelp,19, 5, "Developer Nigel Griffiths see http://nmon.sourceforge.net");
			DISPLAY(padhelp,20);

		}
/*
		if(error_on && errorstr[0] != 0) {
			mvprintw(x, 0, "Error: %s  ",errorstr);
			x = x + 1;
		}
*/
		if (show_cpu && cursed) {
			proc_read(P_CPUINFO);
			proc_read(P_VERSION);

			BANNER(padcpu,"Linux and Processor Details");
			mvwprintw(padcpu,1, 4, "Linux: %s", proc[P_VERSION].line[0]);
			mvwprintw(padcpu,2, 4, "Build: %s", proc[P_VERSION].line[1]);
			mvwprintw(padcpu,3, 4, "Release  : %s", uts.release );
			mvwprintw(padcpu,4, 4, "Version  : %s", uts.version);
#ifdef POWER
			mvwprintw(padcpu,5, 4, "cpuinfo: %s", proc[P_CPUINFO].line[1]);
			mvwprintw(padcpu,6, 4, "cpuinfo: %s", proc[P_CPUINFO].line[2]);
			mvwprintw(padcpu,7, 4, "cpuinfo: %s", proc[P_CPUINFO].line[3]);
			mvwprintw(padcpu,8, 4, "cpuinfo: %s", proc[P_CPUINFO].line[proc[P_CPUINFO].lines-1]);
			/* needs lparcfg to be already processed */
			proc_lparcfg();
			mvwprintw(padcpu,9, 4, "phys/virt CPUs:%3d  logical CPU (SMT):%3d", lparcfg.partition_active_processors, cpus);
#else 
#ifdef MAINFRAME
			mvwprintw(padcpu,5, 4, "cpuinfo: %s", proc[P_CPUINFO].line[1]);
			mvwprintw(padcpu,6, 4, "cpuinfo: %s", proc[P_CPUINFO].line[2]);
			mvwprintw(padcpu,7, 4, "cpuinfo: %s", proc[P_CPUINFO].line[3]);
			mvwprintw(padcpu,8, 4, "cpuinfo: %s", proc[P_CPUINFO].line[4]);
#else /* Intel is the default */
			mvwprintw(padcpu,5, 4, "cpuinfo: %s", proc[P_CPUINFO].line[4]);
			mvwprintw(padcpu,6, 4, "cpuinfo: %s", proc[P_CPUINFO].line[1]);
			mvwprintw(padcpu,7, 4, "cpuinfo: %s", proc[P_CPUINFO].line[6]);
			mvwprintw(padcpu,8, 4, "cpuinfo: %s", proc[P_CPUINFO].line[17]);
#endif /*MAINFRAME*/
			mvwprintw(padcpu,9, 4, "# of CPUs: %d", cpus);
#endif /*POWER*/
			mvwprintw(padcpu,10, 4,"Machine  : %s", uts.machine);
			mvwprintw(padcpu,11, 4,"Nodename : %s", uts.nodename);
			mvwprintw(padcpu,12, 4,"/etc/*ease[1]: %s", easy[0]);
			mvwprintw(padcpu,13, 4,"/etc/*ease[2]: %s", easy[1]);
			mvwprintw(padcpu,14, 4,"/etc/*ease[3]: %s", easy[2]);
			mvwprintw(padcpu,15, 4,"/etc/*ease[4]: %s", easy[3]);
			mvwprintw(padcpu,16, 4,"lsb_release: %s", lsb_release[0]);
			mvwprintw(padcpu,17, 4,"lsb_release: %s", lsb_release[1]);
			mvwprintw(padcpu,18, 4,"lsb_release: %s", lsb_release[2]);
			mvwprintw(padcpu,19, 4,"lsb_release: %s", lsb_release[3]);
			DISPLAY(padcpu,20);
		}
		if (show_longterm ) {
				proc_read(P_STAT);
				proc_cpu();
				cpu_user = p->cpu_total.user - q->cpu_total.user; 
				cpu_sys  = p->cpu_total.sys  - q->cpu_total.sys; 
				cpu_wait = p->cpu_total.wait - q->cpu_total.wait; 
				cpu_idle = p->cpu_total.idle - q->cpu_total.idle; 
				cpu_sum = cpu_idle + cpu_user + cpu_sys + cpu_wait;

				plot_save(
				    (double)cpu_user / (double)cpu_sum * 100.0,
				    (double)cpu_sys  / (double)cpu_sum * 100.0,
				    (double)cpu_wait / (double)cpu_sum * 100.0,
				    (double)cpu_idle / (double)cpu_sum * 100.0);
				plot_snap(padlong);
				DISPLAY(padlong,MAX_SNAP_ROWS+2);
		}
		if (show_smp || show_verbose) {
			if(cpus>max_cpus && !cursed) {
				for (i = max_cpus+1; i <= cpus; i++)
					fprintf(fp,"CPU%03d,CPU %d %s,User%%,Sys%%,Wait%%,Idle%%\n", i, i, run_name);
				max_cpus= cpus;
			}
			if( old_cpus != cpus )	{
				if( !cursed )	{
					if( bbbr_line == 0)	{
						fprintf(fp,"BBBR,0,Reconfig,action,old,new\n");
						bbbr_line++;
					}
					fprintf(fp,"BBBR,%03d,%s,cpuchg,%d,%d\n",bbbr_line++,LOOP,old_cpus,cpus);
				}
				else 	{
					/* wmove(padsmp,0,0); */
					/* doesn't work CURSE wclrtobot(padsmp); */
					/* Do BRUTE force overwrite of previous data */
					if( cpus < old_cpus)	{
						for(i=cpus; i < old_cpus; i++)
							mvwprintw(padsmp,i+4,0,"                                                                                    ");
					}
				}
			}
		    if (show_smp) {
		    	if(cursed) {
					BANNER(padsmp,"CPU Utilisation");

					/* mvwprintw(padsmp,1, 0, cpu_line);*/
					/*
					 *mvwprintw(padsmp,2, 0, "CPU  User%%  Sys%% Wait%% Idle|0          |25         |50          |75       100|");
					 */
					mvwprintw(padsmp,1, 0, cpu_line);
					mvwprintw(padsmp,2, 0, "CPU  ");
					COLOUR wattrset(padsmp, COLOR_PAIR(2));
					mvwprintw(padsmp,2, 5, "User%%");
					COLOUR wattrset(padsmp, COLOR_PAIR(1));
					mvwprintw(padsmp,2, 10, "  Sys%%");
					COLOUR wattrset(padsmp, COLOR_PAIR(4));
					mvwprintw(padsmp,2, 16, " Wait%%");
					COLOUR wattrset(padsmp, COLOR_PAIR(0));
					mvwprintw(padsmp,2, 22, " Idle|0          |25         |50          |75       100|");

				}	/* if (show_smp) AND if(cursed) */
				proc_read(P_STAT);
				proc_cpu();
#ifdef POWER
				/* Always get lpar info as well so we can report physical CPU usage
				 * to make data more meaningful
				 * This assumes that LPAR info is available in q and p !
				 */
				if( proc_lparcfg() > 0 )	{
					if( lparcfg.shared_processor_mode == 1)	{
						if(lparcfg.timebase == -1) {
							lparcfg.timebase=0;
							proc_read(P_CPUINFO);
							for(i=0;i<proc[P_CPUINFO].lines-1;i++) {
								if(!strncmp("timebase",proc[P_CPUINFO].line[i],8)) {
									sscanf(proc[P_CPUINFO].line[i],"timebase : %lld",&lparcfg.timebase);
									break;
								}
							}
						}
						else {
							if( lparcfg.purr_diff == 0 ) {
								mvwprintw(padsmp,1,29," Phys. CPU used: <not available>");
							} else {
								mvwprintw(padsmp,1,29," Phys. CPU used:% 7.2f ",
										(double)lparcfg.purr_diff/(double)lparcfg.timebase/elapsed);
							}
						}
					}
				}
#endif
				for (i = 0; i < cpus; i++) {
					cpu_user = p->cpuN[i].user - q->cpuN[i].user;
					cpu_sys  = p->cpuN[i].sys  - q->cpuN[i].sys;
					cpu_wait = p->cpuN[i].wait - q->cpuN[i].wait;
					cpu_idle = p->cpuN[i].idle - q->cpuN[i].idle;
					cpu_sum = cpu_idle + cpu_user + cpu_sys + cpu_wait;
					/* Check if we had a CPU # change and have to set idle to 100 */
					if( cpu_sum == 0)
						cpu_sum = cpu_idle = 100.0;
					if(smp_first_time && cursed) {
						mvwprintw(padsmp,3 + i, 27, "| Please wait gathering data");
					} else {
						if(!show_raw)
							plot_smp(padsmp,i+1, 3 + i,
							(double)cpu_user / (double)cpu_sum * 100.0,
							(double)cpu_sys  / (double)cpu_sum * 100.0,
							(double)cpu_wait / (double)cpu_sum * 100.0,
							(double)cpu_idle / (double)cpu_sum * 100.0);
						else
							save_smp(padsmp,i+1, 3+i,
							  RAW(user) - RAW(nice),
							  RAW(sys),
							  RAW(wait),
							  RAW(idle),
							  RAW(nice),
							  RAW(irq),
							  RAW(softirq),
							  RAW(steal));
					   RRD fprintf(fp,"rrdtool update cpu%02d.rrd %s:%.1f:%.1f:%.1f:%.1f\n",i,LOOP,
						(double)cpu_user / (double)cpu_sum * 100.0,
						(double)cpu_sys  / (double)cpu_sum * 100.0,
						(double)cpu_wait / (double)cpu_sum * 100.0,
						(double)cpu_idle / (double)cpu_sum * 100.0);
					}
				}	/* for (i = 0; i < cpus; i++) */
				CURSE mvwprintw(padsmp,i + 3, 0, cpu_line);
				cpu_user = p->cpu_total.user - q->cpu_total.user;
				cpu_sys  = p->cpu_total.sys  - q->cpu_total.sys;
				cpu_wait = p->cpu_total.wait - q->cpu_total.wait;
				cpu_idle = p->cpu_total.idle - q->cpu_total.idle;
				cpu_sum = cpu_idle + cpu_user + cpu_sys + cpu_wait;

				/* Check if we had a CPU # change and have to set idle to 100 */
				if( cpu_sum == 0)
					cpu_sum = cpu_idle = 100.0;

				RRD fprintf(fp,"rrdtool update cpu.rrd %s:%.1f:%.1f:%.1f:%.1f\n",LOOP,
						(double)cpu_user / (double)cpu_sum * 100.0,
						(double)cpu_sys  / (double)cpu_sum * 100.0,
						(double)cpu_wait / (double)cpu_sum * 100.0,
						(double)cpu_idle / (double)cpu_sum * 100.0);
				if (cpus > 1 || !cursed) {
					if(!smp_first_time || !cursed) {
						if(!show_raw) {
							plot_smp(padsmp,0, 4 + i,
							(double)cpu_user / (double)cpu_sum * 100.0,
							(double)cpu_sys  / (double)cpu_sum * 100.0,
							(double)cpu_wait / (double)cpu_sum * 100.0,
							(double)cpu_idle / (double)cpu_sum * 100.0);
						} else {
							save_smp(padsmp,0, 4+i,
							  RAWTOTAL(user) - RAWTOTAL(nice),
							  RAWTOTAL(sys),
							  RAWTOTAL(wait),
							  RAWTOTAL(idle),
							  RAWTOTAL(nice),
							  RAWTOTAL(irq),
							  RAWTOTAL(softirq),
							  RAWTOTAL(steal));
						}
					}

					CURSE mvwprintw(padsmp, i + 5, 0, cpu_line);
					i = i + 2;
				} /* if (cpus > 1 || !cursed) */
				smp_first_time=0;
				DISPLAY(padsmp, i + 4);
			}	/* if (show_smp) { */
			if(show_verbose && cursed) {
				cpu_user = p->cpu_total.user - q->cpu_total.user; 
				cpu_sys  = p->cpu_total.sys  - q->cpu_total.sys; 
				cpu_wait = p->cpu_total.wait - q->cpu_total.wait; 
				cpu_idle = p->cpu_total.idle - q->cpu_total.idle; 
				cpu_sum = cpu_idle + cpu_user + cpu_sys + cpu_wait;

				cpu_busy= (double)(cpu_user + cpu_sys)/ (double)cpu_sum * 100.0; 
				mvwprintw(padverb,2, 0, "        -> CPU               %%busy %5.1f%%\t>80%%\t>90%%          ",cpu_busy);
				if(cpu_busy > 90.0){
					COLOUR wattrset(padverb,COLOR_PAIR(1));
					mvwprintw(padverb,2, 0, " DANGER");
				}
				else if(cpu_busy > 80.0) {
					COLOUR wattrset(padverb,COLOR_PAIR(4));
					mvwprintw(padverb,2, 0, "Warning");
				}
				else  {
					COLOUR wattrset(padverb,COLOR_PAIR(2));
					mvwprintw(padverb,2, 0, "     OK");
				}
				COLOUR wattrset(padverb,COLOR_PAIR(0));
			}	/* if(show_verbose && cursed) */
		}	/* if (show_smp || show_verbose) */
#ifdef POWER
		if (show_lpar) {
			if(lparcfg.timebase == -1) {
				lparcfg.timebase=0;
				proc_read(P_CPUINFO);
				for(i=0;i<proc[P_CPUINFO].lines-1;i++) {
					if(!strncmp("timebase",proc[P_CPUINFO].line[i],8)) {
						sscanf(proc[P_CPUINFO].line[i],"timebase : %lld",&lparcfg.timebase);
						break;
					}
				}
			}
			ret = proc_lparcfg();
			if(cursed) {
				BANNER(padlpar,"LPAR Stats");
				if(ret == 0) {
				mvwprintw(padlpar,2, 0, "Reading data from /proc/ppc64/lparcfg failed");
				mvwprintw(padlpar,3, 0, "Either run as the root user or ");
				mvwprintw(padlpar,4, 0, "as the root user run: chmod ugo+r /proc/ppc64/lparcfg");
				} else {
				mvwprintw(padlpar,1, 0, "LPAR=%d  SerialNumber=%s  Type=%s",
					lparcfg.partition_id, lparcfg.serial_number, lparcfg.system_type);
				mvwprintw(padlpar,2, 0, "Flags:      Shared-CPU=%-5s  Capped=%-5s   SMT-mode=%-7s",
					lparcfg.shared_processor_mode?"true":"false",
					lparcfg.capped?"true":"false",
					lparcfg.smt_mode == 1 ? "off" : lparcfg.smt_mode==2 ? "SMT-2" : lparcfg.smt_mode==4 ? "SMT-4" : "unknown");
				mvwprintw(padlpar,3, 0, "Systems CPU Pool=%8.2f          Active=%8.2f    Total=%8.2f",
					(float)lparcfg.pool_capacity,
					(float)lparcfg.system_active_processors,
					(float)lparcfg.system_potential_processors);
				mvwprintw(padlpar,4, 0, "LPARs CPU    Min=%8.2f     Entitlement=%8.2f      Max=%8.2f",
					lparcfg.MinEntCap/100.0,
					lparcfg.partition_entitled_capacity/100.0,
					lparcfg.partition_max_entitled_capacity/100.0);
				mvwprintw(padlpar,5, 0, "Virtual CPU  Min=%8.2f          VP Now=%8.2f      Max=%8.2f",
					(float)lparcfg.MinProcs,
					(float)lparcfg.partition_active_processors,
					(float)lparcfg.partition_potential_processors);
				mvwprintw(padlpar,6, 0, "Memory       Min= unknown             Now=%8.2f      Max=%8.2f",
					(float)lparcfg.MinMem,
					(float)lparcfg.DesMem);
				mvwprintw(padlpar,7, 0, "Other     Weight=%8.2f   UnallocWeight=%8.2f Capacity=%8.2f",
					(float)lparcfg.capacity_weight,
					(float)lparcfg.unallocated_capacity_weight,
					(float)lparcfg.CapInc/100.0);

				mvwprintw(padlpar,8, 0, "      BoundThrds=%8.2f UnallocCapacity=%8.2f  Increment",
					(float)lparcfg.BoundThrds,
					(float)lparcfg.unallocated_capacity);
				if(lparcfg.purr_diff == 0 || lparcfg.timebase <1) {
					mvwprintw(padlpar,9, 0, "lparcfg: purr field always zero, upgrade to SLES9+sp1 or RHEL4+u1");
				} else {
                                        if(lpar_first_time) {
					    mvwprintw(padlpar,9, 0, "Please wait gathering data");

                                            lpar_first_time=0;
                                        } else {
					    mvwprintw(padlpar,9, 0, "Physical CPU use=%8.3f ",
							(double)lparcfg.purr_diff/(double)lparcfg.timebase/elapsed);
					    if( lparcfg.pool_idle_time != NUMBER_NOT_VALID && lparcfg.pool_idle_saved != 0)
						    mvwprintw(padlpar,9, 29, "PoolIdleTime=%8.2f",
							(double)lparcfg.pool_idle_diff/(double)lparcfg.timebase/elapsed);
					    mvwprintw(padlpar,9, 54, "[timebase=%lld]", lparcfg.timebase);
					}
                                       }
				}
				DISPLAY(padlpar,10);
			} else {
				/* Only print LPAR info to spreadsheet if in shared processor mode */
				if(ret != 0 && lparcfg.shared_processor_mode > 0)
				    fprintf(fp,"LPAR,%s,%9.6f,%d,%d,%d,%d,%d,%.1f,%.1f,%.1f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lld\n",
					LOOP,
					(double)lparcfg.purr_diff/(double)lparcfg.timebase/elapsed,
					lparcfg.capped,
					lparcfg.shared_processor_mode,
					lparcfg.system_potential_processors,
					lparcfg.system_active_processors,
					lparcfg.pool_capacity,
					lparcfg.MinEntCap/100.0,
					lparcfg.partition_entitled_capacity/100.0,
					lparcfg.partition_max_entitled_capacity/100.0,
					lparcfg.MinProcs,
					cpus, 		/* report logical CPU here so analyser graph CPU% vs VPs reports correctly */
					lparcfg.partition_active_processors,
					lparcfg.partition_potential_processors,
					lparcfg.capacity_weight,
					lparcfg.unallocated_capacity_weight,
					lparcfg.BoundThrds,
					lparcfg.MinMem,
					lparcfg.unallocated_capacity,
					lparcfg.pool_idle_time);
			}
		}
#endif /*POWER*/
		if (show_memory) {
			proc_read(P_MEMINFO);
			proc_mem();
			if(cursed) {
				BANNER(padmem,"Memory Stats");
				mvwprintw(padmem,1, 1, "               RAM     High      Low     Swap    Page Size=%d KB",pagesize/1024);
				mvwprintw(padmem,2, 1, "Total MB    %8.1f %8.1f %8.1f %8.1f ",
					p->mem.memtotal/1024.0,
					p->mem.hightotal/1024.0,
					p->mem.lowtotal/1024.0,
					p->mem.swaptotal/1024.0);
				mvwprintw(padmem,3, 1, "Free  MB    %8.1f %8.1f %8.1f %8.1f ",
					p->mem.memfree/1024.0,
					p->mem.highfree/1024.0,
					p->mem.lowfree/1024.0,
					p->mem.swapfree/1024.0);
				mvwprintw(padmem,4, 1, "Free Percent %7.1f%% %7.1f%% %7.1f%% %7.1f%% ",
					p->mem.memfree  == 0 ? 0.0 : 100.0*(float)p->mem.memfree/(float)p->mem.memtotal,
					p->mem.highfree == 0 ? 0.0 : 100.0*(float)p->mem.highfree/(float)p->mem.hightotal,
					p->mem.lowfree  == 0 ? 0.0 : 100.0*(float)p->mem.lowfree/(float)p->mem.lowtotal,
					p->mem.swapfree == 0 ? 0.0 : 100.0*(float)p->mem.swapfree/(float)p->mem.swaptotal);


				mvwprintw(padmem,5, 1, "            MB                  MB                  MB");
#ifdef LARGEMEM
				mvwprintw(padmem,6, 1, "                     Cached=%8.1f     Active=%8.1f",
					p->mem.cached/1024.0,
					p->mem.active/1024.0);
#else
				mvwprintw(padmem,6, 1, " Shared=%8.1f     Cached=%8.1f     Active=%8.1f",
					p->mem.memshared/1024.0,
					p->mem.cached/1024.0,
					p->mem.active/1024.0);
				mvwprintw(padmem,5, 68, "MB");
				mvwprintw(padmem,6, 55, "bigfree=%8.1f",
					p->mem.bigfree/1024);
#endif /*LARGEMEM*/
				mvwprintw(padmem,7, 1, "Buffers=%8.1f Swapcached=%8.1f  Inactive =%8.1f",
					p->mem.buffers/1024.0,
					p->mem.swapcached/1024.0,
					p->mem.inactive/1024.0);

				mvwprintw(padmem,8, 1, "Dirty  =%8.1f Writeback =%8.1f  Mapped   =%8.1f",
					p->mem.dirty/1024.0,
					p->mem.writeback/1024.0,
					p->mem.mapped/1024.0);
				mvwprintw(padmem,9, 1, "Slab   =%8.1f Commit_AS =%8.1f PageTables=%8.1f",
					p->mem.slab/1024.0,
					p->mem.committed_as/1024.0,
					p->mem.pagetables/1024.0);
#ifdef POWER
				if(!show_lpar) /* check if already called above */
					proc_lparcfg();
				if(lparcfg.cmo_enabled == 0)
					mvwprintw(padmem,10, 1, "AMS is not active");
				else
					mvwprintw(padmem,10, 1, "AMS id=%d Weight=%-3d pmem=%ldMB hpi=%.1f/s hpit=%.1f(sec) Pool=%ldMB Loan=%ldKB     ",
					(int)lparcfg.entitled_memory_pool_number,
					(int)lparcfg.entitled_memory_weight,
					(long)(lparcfg.backing_memory)/1024/1024, 
					(double)(lparcfg.cmo_faults_diff)/elapsed,
					(double)(lparcfg.cmo_fault_time_usec_diff)/1000/1000/elapsed,
					(long)lparcfg.entitled_memory_pool_size/1024/1024,
					(long)lparcfg.entitled_memory_loan_request/1024);

				DISPLAY(padmem,11);
#else /* POWER */
				DISPLAY(padmem,10);
#endif /* POWER */
			} else {

				if(show_rrd) 
				   str_p = "rrdtool update mem.rrd %s:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f\n";
				else
				   str_p = "MEM,%s,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n";
				   fprintf(fp,str_p,
					LOOP,
					p->mem.memtotal/1024.0,
					p->mem.hightotal/1024.0,
					p->mem.lowtotal/1024.0,
					p->mem.swaptotal/1024.0,
					p->mem.memfree/1024.0,
					p->mem.highfree/1024.0,
					p->mem.lowfree/1024.0,
					p->mem.swapfree/1024.0,
					p->mem.memshared/1024.0,
					p->mem.cached/1024.0,
					p->mem.active/1024.0,
#ifdef LARGEMEM
					-1.0,
#else
					p->mem.bigfree/1024.0,
#endif /*LARGEMEM*/
					p->mem.buffers/1024.0,
					p->mem.swapcached/1024.0,
					p->mem.inactive/1024.0);
#ifdef POWER
				   if(lparcfg.cmo_enabled != 0) {
					   if(!show_rrd)fprintf(fp,"MEMAMS,%s,%d,%d,%.1f,%.3lf,0,0,0,%.1f,%ld,%ld,%ld\n",
						LOOP,
						(int)lparcfg.entitled_memory_pool_number,
						(int)lparcfg.entitled_memory_weight,
						(float)(lparcfg.cmo_faults_diff)/elapsed,
						(float)(lparcfg.cmo_fault_time_usec_diff)/1000/1000/elapsed,
						/* three zeros here */
						(float)(lparcfg.backing_memory)/1024/1024,
						lparcfg.cmo_page_size/1024,
						lparcfg.entitled_memory_pool_size/1024/1024,
						lparcfg.entitled_memory_loan_request/1024);
				  }
#ifdef EXPERIMENTAL
				  if(!show_rrd)fprintf(fp,"MEMEXPERIMENTAL,%s,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld\n",
					LOOP,
					(long)lparcfg.DesEntCap,
					(long)lparcfg.DesProcs,
					(long)lparcfg.DesVarCapWt,
					(long)lparcfg.DedDonMode,
					(long)lparcfg.group,
					(long)lparcfg.pool,
					(long)lparcfg.entitled_memory,
					(long)lparcfg.entitled_memory_group_number,
					(long)lparcfg.unallocated_entitled_memory_weight,
					(long)lparcfg.unallocated_io_mapping_entitlement);
#endif /* EXPERIMENTAL */
#endif /* POWER */
			}
/* for testing large page		
		p->mem.hugefree = 250;
		p->mem.hugetotal = 1000;
		p->mem.hugesize = 16*1024;
*/
		}
		if (show_large) {
			proc_read(P_MEMINFO);
			proc_mem();
			if(cursed) {
				BANNER(padlarge,"Large (Huge) Page Stats");
			    if(p->mem.hugetotal > 0) {
				if(p->mem.hugetotal - p->mem.hugefree > huge_peak)
					huge_peak = p->mem.hugetotal - p->mem.hugefree; 
				mvwprintw(padlarge,1, 1, "Total Pages=%7ld   100.0%%   Huge Page Size =%ld KB",    p->mem.hugetotal, p->mem.hugesize);
				mvwprintw(padlarge,2, 1, "Used  Pages=%7ld   %5.1f%%   Used Pages Peak=%-8ld",    
				(long)(p->mem.hugetotal - p->mem.hugefree), 
				(p->mem.hugetotal - p->mem.hugefree)/(float)p->mem.hugetotal*100.0, 
				huge_peak);
				mvwprintw(padlarge,3, 1, "Free  Pages=%7ld   %5.1f%%",    p->mem.hugefree, p->mem.hugefree/(float)p->mem.hugetotal*100.0);
			    } else {
				mvwprintw(padlarge,1, 1, " There are no Huge Pages");
				mvwprintw(padlarge,2, 1, " - see /proc/meminfo");
			    }
				DISPLAY(padlarge,4);
			} else {
				if(p->mem.hugetotal > 0) {
					if(first_huge == 1){
						first_huge=0;
						fprintf(fp,"HUGEPAGES,Huge Page Use %s,HugeTotal,HugeFree,HugeSizeMB\n", run_name);
					}
					fprintf(fp,"HUGEPAGES,%s,%ld,%ld,%.1f\n", 
						LOOP,
						p->mem.hugetotal,
						p->mem.hugefree,
						p->mem.hugesize/1024.0);
				}
			}
		}
		if (show_vm) {
#define VMDELTA(variable) (p->vm.variable - q->vm.variable)
#define VMCOUNT(variable) (p->vm.variable                 )
			ret = read_vmstat();
			if(cursed) {
				BANNER(padpage,"Virtual-Memory");
				if(ret < 0 ) {
				    mvwprintw(padpage,2, 2, "Virtual Memory stats not supported with this kernel");
				    mvwprintw(padpage,3, 2, "/proc/vmstat only seems to appear in 2.6 onwards");

				} else {
				  if(vm_first_time) {
				    mvwprintw(padpage,2, 2, "Please wait - collecting data");
				    vm_first_time=0;
				  } else {
				    mvwprintw(padpage,1, 0, "nr_dirty    =%9lld pgpgin      =%8lld",
					VMCOUNT(nr_dirty),
					VMDELTA(pgpgin));
				    mvwprintw(padpage,2, 0, "nr_writeback=%9lld pgpgout     =%8lld",
					VMCOUNT(nr_writeback),
					VMDELTA(pgpgout));
				    mvwprintw(padpage,3, 0, "nr_unstable =%9lld pgpswpin    =%8lld",
					VMCOUNT(nr_unstable),
					VMDELTA(pswpin));
				    mvwprintw(padpage,4, 0, "nr_table_pgs=%9lld pgpswpout   =%8lld",
					VMCOUNT(nr_page_table_pages),
					VMDELTA(pswpout));
				    mvwprintw(padpage,5, 0, "nr_mapped   =%9lld pgfree      =%8lld",
					VMCOUNT(nr_mapped),
					VMDELTA(pgfree));
				    mvwprintw(padpage,6, 0, "nr_slab     =%9lld pgactivate  =%8lld",
					VMCOUNT(nr_slab),
					VMDELTA(pgactivate));
				    mvwprintw(padpage,7, 0, "                       pgdeactivate=%8lld",
					VMDELTA(pgdeactivate));
				    mvwprintw(padpage,8, 0, "allocstall  =%9lld pgfault     =%8lld  kswapd_steal     =%7lld",
					VMDELTA(allocstall),
					VMDELTA(pgfault),
					VMDELTA(kswapd_steal));
				    mvwprintw(padpage,9, 0, "pageoutrun  =%9lld pgmajfault  =%8lld  kswapd_inodesteal=%7lld",
					VMDELTA(pageoutrun),
					VMDELTA(pgmajfault),
					VMDELTA(kswapd_inodesteal));
				    mvwprintw(padpage,10, 0,"slabs_scanned=%8lld pgrotated   =%8lld  pginodesteal     =%7lld",
					VMDELTA(slabs_scanned),
					VMDELTA(pgrotated),
					VMDELTA(pginodesteal));



				    mvwprintw(padpage,1, 46, "              High Normal    DMA");
				    mvwprintw(padpage,2, 46, "alloc      %7lld%7lld%7lld",
					VMDELTA(pgalloc_high),
					VMDELTA(pgalloc_normal),
					VMDELTA(pgalloc_dma));
				    mvwprintw(padpage,3, 46, "refill     %7lld%7lld%7lld",
					VMDELTA(pgrefill_high),
					VMDELTA(pgrefill_normal),
					VMDELTA(pgrefill_dma));
				    mvwprintw(padpage,4, 46, "steal      %7lld%7lld%7lld",
					VMDELTA(pgsteal_high),
					VMDELTA(pgsteal_normal),
					VMDELTA(pgsteal_dma));
				    mvwprintw(padpage,5, 46, "scan_kswapd%7lld%7lld%7lld",
					VMDELTA(pgscan_kswapd_high),
					VMDELTA(pgscan_kswapd_normal),
					VMDELTA(pgscan_kswapd_dma));
				    mvwprintw(padpage,6, 46, "scan_direct%7lld%7lld%7lld",
					VMDELTA(pgscan_direct_high),
					VMDELTA(pgscan_direct_normal),
					VMDELTA(pgscan_direct_dma));
				  }
				}
				DISPLAY(padpage,11);
			} else {
				if( ret < 0) {
					show_vm=0;
				} else if(vm_first_time) {
					vm_first_time=0;
fprintf(fp,"VM,Paging and Virtual Memory,nr_dirty,nr_writeback,nr_unstable,nr_page_table_pages,nr_mapped,nr_slab,pgpgin,pgpgout,pswpin,pswpout,pgfree,pgactivate,pgdeactivate,pgfault,pgmajfault,pginodesteal,slabs_scanned,kswapd_steal,kswapd_inodesteal,pageoutrun,allocstall,pgrotated,pgalloc_high,pgalloc_normal,pgalloc_dma,pgrefill_high,pgrefill_normal,pgrefill_dma,pgsteal_high,pgsteal_normal,pgsteal_dma,pgscan_kswapd_high,pgscan_kswapd_normal,pgscan_kswapd_dma,pgscan_direct_high,pgscan_direct_normal,pgscan_direct_dma\n");
				} 
				if(show_rrd)
					str_p = "rrdtool update vm.rrd %s" 
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld:%lld:%lld:%lld"
					":%lld:%lld\n";
				else
					str_p = "VM,%s" 
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld,%lld,%lld,%lld"
					",%lld,%lld\n";

				fprintf(fp, str_p,
					LOOP,
					VMCOUNT(nr_dirty),
					VMCOUNT(nr_writeback),
					VMCOUNT(nr_unstable),
					VMCOUNT(nr_page_table_pages),
					VMCOUNT(nr_mapped),
					VMCOUNT(nr_slab),
					VMDELTA(pgpgin),
					VMDELTA(pgpgout),
					VMDELTA(pswpin),
					VMDELTA(pswpout),
					VMDELTA(pgfree),
					VMDELTA(pgactivate),
					VMDELTA(pgdeactivate),
					VMDELTA(pgfault),
					VMDELTA(pgmajfault),
					VMDELTA(pginodesteal),
					VMDELTA(slabs_scanned),
					VMDELTA(kswapd_steal),
					VMDELTA(kswapd_inodesteal),
					VMDELTA(pageoutrun),
					VMDELTA(allocstall),
					VMDELTA(pgrotated),
					VMDELTA(pgalloc_high),
					VMDELTA(pgalloc_normal),
					VMDELTA(pgalloc_dma),
					VMDELTA(pgrefill_high),
					VMDELTA(pgrefill_normal),
					VMDELTA(pgrefill_dma),
					VMDELTA(pgsteal_high),
					VMDELTA(pgsteal_normal),
					VMDELTA(pgsteal_dma),
					VMDELTA(pgscan_kswapd_high),
					VMDELTA(pgscan_kswapd_normal),
					VMDELTA(pgscan_kswapd_dma),
					VMDELTA(pgscan_direct_high),
					VMDELTA(pgscan_direct_normal),
					VMDELTA(pgscan_direct_dma));
			}
		}
		if (show_kernel) {
			proc_read(P_STAT);
			proc_cpu();
			proc_read(P_UPTIME);
			proc_read(P_LOADAVG);
			proc_kernel();
			if(cursed) {
				BANNER(padker,"Kernel Stats");
				mvwprintw(padker,1, 1, "RunQueue       %8lld   Load Average    CPU use since boot time",
					p->cpu_total.running);
					updays=p->cpu_total.uptime/60/60/24;
					uphours=(p->cpu_total.uptime-updays*60*60*24)/60/60;
					upmins=(p->cpu_total.uptime-updays*60*60*24-uphours*60*60)/60;
				mvwprintw(padker,2, 1, "ContextSwitch  %8.1f    1 mins %5.2f    Uptime Days=%3d Hours=%2d Mins=%2d",
					(float)(p->cpu_total.ctxt - q->cpu_total.ctxt)/elapsed,
					(float)p->cpu_total.mins1,
					updays, uphours, upmins);
					updays=p->cpu_total.idletime/60/60/24;
					uphours=(p->cpu_total.idletime-updays*60*60*24)/60/60;
					upmins=(p->cpu_total.idletime-updays*60*60*24-uphours*60*60)/60;
				mvwprintw(padker,3, 1, "Forks          %8.1f    5 mins %5.2f    Idle   Days=%3d Hours=%2d Mins=%2d",
					(float)(p->cpu_total.procs - q->cpu_total.procs)/elapsed,
					(float)p->cpu_total.mins5,
					updays, uphours, upmins);

				mvwprintw(padker,4, 1, "Interrupts     %8.1f   15 mins %5.2f    Average CPU use=%6.2f%%",
					(float)(p->cpu_total.intr - q->cpu_total.intr)/elapsed,
					(float)p->cpu_total.mins15,
					(float)(
					(p->cpu_total.uptime -
					p->cpu_total.idletime)/
					p->cpu_total.uptime *100.0));
				DISPLAY(padker,5);
			} else {
				if(proc_first_time) {
					q->cpu_total.ctxt = p->cpu_total.ctxt;
					q->cpu_total.procs= p->cpu_total.procs;
					proc_first_time=0;
				}
				if(show_rrd)
					str_p = "rrdtool update proc.rrd %s:%.0f:%.0f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f:%.1f\n";
				else
					str_p = "PROC,%s,%.0f,%.0f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\n";

				fprintf(fp,str_p,
					LOOP,
					(float)p->cpu_total.running,/*runqueue*/
					(float)p->cpu_total.blocked,/*swapin (# of processes waiting for IO completion */
								/*pswitch*/
					(float)(p->cpu_total.ctxt - q->cpu_total.ctxt)/elapsed,	
					-1.0,		/*syscall*/
					-1.0,		/*read*/
					-1.0,		/*write*/
							/*fork*/
					(float)(p->cpu_total.procs - q->cpu_total.procs)/elapsed,
					-1.0,		/*exec*/
					-1.0,		/*sem*/
					-1.0);		/*msg*/
			}
		}

		if (show_nfs) {
			proc_read(P_NFS);
			proc_read(P_NFSD);
			proc_nfs();

			if(cursed) {
				if(nfs_first_time) {
					memcpy(&q->nfs,&p->nfs,sizeof(struct nfs_stat));
					nfs_first_time=0;
				}
				if(nfs_clear) {
					nfs_clear=0;
					for(i=0;i<25;i++)
					mvwprintw(padnfs,i, 0, "                                                                                ");
				}
				BANNER(padnfs,"Network Filesystem (NFS) I/O Operations per second");
				if(show_nfs == 1) {
				mvwprintw(padnfs,1, 0, " Version 2       Client   Server");
				mvwprintw(padnfs,1, 41, "Version 3      Client   Server");
				} else {
				mvwprintw(padnfs,1, 0, " Version 4 Client               Client");
				mvwprintw(padnfs,1, 42, "Version 4 Server              Server");

				}
#define NFS_TOTAL(member) (double)(p->member)
#define NFS_DELTA(member) (((double)(p->member - q->member)/elapsed))
					v2c_total =0;
					v2s_total =0;
					v3c_total =0;
					v3s_total =0;
					v4c_total =0;
					v4s_total =0;
				for(i=0;i<18;i++) {
					if(show_nfs == 1) 
						mvwprintw(padnfs,2+i,  3, "%12s %8.1f %8.1f",
						nfs_v2_names[i],
						NFS_DELTA(nfs.v2c[i]),
						NFS_DELTA(nfs.v2s[i]));
					v2c_total +=NFS_DELTA(nfs.v2c[i]);
					v2s_total +=NFS_DELTA(nfs.v2s[i]);
				}
				for(i=0;i<22;i++) {
					if(show_nfs == 1)
						mvwprintw(padnfs,2+i, 41, "%12s %8.1f %8.1f",
						nfs_v3_names[i],
						NFS_DELTA(nfs.v3c[i]),
						NFS_DELTA(nfs.v3s[i]));
					v3c_total +=NFS_DELTA(nfs.v3c[i]);
					v3s_total +=NFS_DELTA(nfs.v3s[i]);
				}
				for(i=0;i<18;i++) {
					if(show_nfs == 2) {
						mvwprintw(padnfs,2+i, 1, "%9s%7.1f",
						nfs_v4c_names[i],
						NFS_DELTA(nfs.v4c[i]));
					}
					v4c_total +=NFS_DELTA(nfs.v4c[i]);
				}
				for(i=18;i<35;i++) {
					if(show_nfs == 2) {
						mvwprintw(padnfs,2+i-18, 19, "%12s%7.1f",
						nfs_v4c_names[i],
						NFS_DELTA(nfs.v4c[i]));
					}
					v4c_total +=NFS_DELTA(nfs.v4c[i]);
				}
				for(i=0;i<20;i++) {
					if(show_nfs == 2) {
						mvwprintw(padnfs,2+i, 40, "%11s%7.1f",
						nfs_v4s_names[i],
						NFS_DELTA(nfs.v4s[i]));
					}
					v4s_total +=NFS_DELTA(nfs.v4s[i]);
				}
				for(i=20;i<40;i++) {
					if(show_nfs == 2) {
						mvwprintw(padnfs,2+i-20, 59, "%12s%7.1f",
						nfs_v4s_names[i],
						NFS_DELTA(nfs.v4s[i]));
					}
					v4s_total +=NFS_DELTA(nfs.v4s[i]);
				}
				mvwprintw(padnfs,2+19,  1, "NFSv2 Totals->%9.1f %9.1f", v2c_total,v2s_total);
				mvwprintw(padnfs,2+20,  1, "NFSv3 Totals->%9.1f %9.1f", v3c_total,v3s_total);
				mvwprintw(padnfs,2+21,  1, "NFSv4 Totals->%9.1f %9.1f", v4c_total,v4s_total);
					
				DISPLAY(padnfs,24);
			} else {
				if(nfs_first_time && ! show_rrd) {
					if(nfs_v2c_found) {
						fprintf(fp,"NFSCLIV2,NFS Client v2");
						for(i=0;i<18;i++) 
							fprintf(fp,",%s",nfs_v2_names[i]);
						fprintf(fp,"\n");
					}
					if(nfs_v2s_found) {
						fprintf(fp,"NFSSVRV2,NFS Server v2");
						for(i=0;i<18;i++) 
							fprintf(fp,",%s",nfs_v2_names[i]);
						fprintf(fp,"\n");
					}

					if(nfs_v3c_found) {
						fprintf(fp,"NFSCLIV3,NFS Client v3");
						for(i=0;i<22;i++) 
							fprintf(fp,",%s",nfs_v3_names[i]);
						fprintf(fp,"\n");
					}
					if(nfs_v3s_found) {
						fprintf(fp,"NFSSVRV3,NFS Server v3");
						for(i=0;i<22;i++) 
							fprintf(fp,",%s",nfs_v3_names[i]);
						fprintf(fp,"\n");
					}

					if(nfs_v4c_found) {
						fprintf(fp,"NFSCLIV4,NFS Client v4");
						for(i=0;i<35;i++) 
							fprintf(fp,",%s",nfs_v4c_names[i]);
						fprintf(fp,"\n");
					}
					if(nfs_v4s_found) {
						fprintf(fp,"NFSSVRV4,NFS Server v4");
						for(i=0;i<40;i++) 
							fprintf(fp,",%s",nfs_v4s_names[i]);
						fprintf(fp,"\n");
					}
					memcpy(&q->nfs,&p->nfs,sizeof(struct nfs_stat));
					nfs_first_time=0;
				}
				if(nfs_v2c_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfscliv2.rrd %s" : "NFSCLIV2,%s", LOOP);
					for(i=0;i<18;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v2c[i]));
					}
					fprintf(fp,"\n");
				}
				if(nfs_v2s_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfsvrv2.rrd %s" : "NFSSVRV2,%s", LOOP);
					for(i=0;i<18;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v2s[i]));
					}
					fprintf(fp,"\n");
				}
				if(nfs_v3c_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfscliv3.rrd %s" : "NFSCLIV3,%s", LOOP);
					for(i=0;i<22;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v3c[i]));
					}
					fprintf(fp,"\n");
				}
				if(nfs_v3s_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfsvrv3.rrd %s" : "NFSSVRV3,%s", LOOP);
					for(i=0;i<22;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v3s[i]));
					}
					fprintf(fp,"\n");
				}

				if(nfs_v4c_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfscliv4.rrd %s" : "NFSCLIV4,%s", LOOP);
					for(i=0;i<35;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v4c[i]));
					}
					fprintf(fp,"\n");
				}
				if(nfs_v4s_found) {
					fprintf(fp,show_rrd ? "rrdtool update nfsvrv4.rrd %s" : "NFSSVRV4,%s", LOOP);
					for(i=0;i<40;i++) {
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f", 
						(double)NFS_DELTA(nfs.v4s[i]));
					}
					fprintf(fp,"\n");
				}
			}
		}
		if (show_net) {
			if(cursed) {
			BANNER(padnet,"Network I/O");
			mvwprintw(padnet,1, 0, "I/F Name Recv=KB/s Trans=KB/s packin packout insize outsize Peak->Recv Trans");
			}
			proc_net();
			for (i = 0; i < networks; i++) {

#define IFDELTA(member) ((float)( (q->ifnets[i].member > p->ifnets[i].member) ? 0 : (p->ifnets[i].member - q->ifnets[i].member)/elapsed) )
#define IFDELTA_ZERO(member1,member2) ((IFDELTA(member1) == 0) || (IFDELTA(member2)== 0)? 0.0 : IFDELTA(member1)/IFDELTA(member2) )

				if(net_read_peak[i] < IFDELTA(if_ibytes) / 1024.0)
					net_read_peak[i] = IFDELTA(if_ibytes) / 1024.0;
				if(net_write_peak[i] < IFDELTA(if_obytes) / 1024.0)
					net_write_peak[i] = IFDELTA(if_obytes) / 1024.0;

				CURSE mvwprintw(padnet,2 + i, 0, "%8s %7.1f %7.1f    %6.1f   %6.1f  %6.1f %6.1f    %7.1f %7.1f   ",
				    &p->ifnets[i].if_name[0],
				    IFDELTA(if_ibytes) / 1024.0,   
				    IFDELTA(if_obytes) / 1024.0, 
				    IFDELTA(if_ipackets), 
				    IFDELTA(if_opackets),
				    IFDELTA_ZERO(if_ibytes, if_ipackets),
				    IFDELTA_ZERO(if_obytes, if_opackets),
				    net_read_peak[i],
				    net_write_peak[i]
					);
			}
			DISPLAY(padnet,networks + 2);
			if (!cursed) {
				fprintf(fp,show_rrd ? "rrdtool update net.rrd %s" : "NET,%s,", LOOP);
				for (i = 0; i < networks; i++) {
					fprintf(fp,show_rrd ? ":%.1f" : "%.1f,", IFDELTA(if_ibytes) / 1024.0);
				}
				for (i = 0; i < networks; i++) {
					fprintf(fp,show_rrd ? ":%.1f" : "%.1f,", IFDELTA(if_obytes) / 1024.0);
				}
				fprintf(fp,"\n");
				fprintf(fp,show_rrd ? "rrdtool update netpacket.rrd %s" : "NETPACKET,%s,", LOOP);
				for (i = 0; i < networks; i++) {
					fprintf(fp,show_rrd ? ":%.1f" : "%.1f,", IFDELTA(if_ipackets) );
				}
				for (i = 0; i < networks; i++) {
					fprintf(fp,show_rrd ? ":%.1f" : "%.1f,", IFDELTA(if_opackets) );
				}
				fprintf(fp,"\n");
			}
		}
		errors=0;
		for (i = 0; i < networks; i++) {
			errors += p->ifnets[i].if_ierrs - q->ifnets[i].if_ierrs
				+ p->ifnets[i].if_oerrs - q->ifnets[i].if_oerrs
				+ p->ifnets[i].if_ocolls - q->ifnets[i].if_ocolls;
		}
		if(errors) show_neterror=3;
		if(show_neterror) {
			if(cursed) {
			BANNER(padneterr,"Network Error Counters");
			mvwprintw(padneterr,1, 0, "I/F Name iErrors iDrop iOverrun iFrame oErrors   oDrop oOverrun oCarrier oColls ");
			}
			for (i = 0; i < networks; i++) {
				CURSE mvwprintw(padneterr,2 + i, 0, "%8s %7lu %7lu %7lu %7lu %7lu %7lu %7lu %7lu %7lu",
				    &p->ifnets[i].if_name[0],
				    p->ifnets[i].if_ierrs,   
				    p->ifnets[i].if_idrop,   
				    p->ifnets[i].if_ififo,   
				    p->ifnets[i].if_iframe,   
				    p->ifnets[i].if_oerrs,   
				    p->ifnets[i].if_odrop,   
				    p->ifnets[i].if_ofifo,   
				    p->ifnets[i].if_ocarrier,   
				    p->ifnets[i].if_ocolls);   

			}
			DISPLAY(padneterr,networks + 2);
			if(show_neterror > 0) show_neterror--;
		}
#ifdef JFS
		if (show_jfs) {
		    if(cursed) {
			BANNER(padjfs,"Filesystems");
			mvwprintw(padjfs,1, 0, "Filesystem            SizeMB  FreeMB  Use%% Type     MountPoint");

			for (k = 0; k < jfses; k++) {
				fs_size=0;
				fs_bsize=0;
				fs_free=0;
				fs_size_used=100.0;
			    if(jfs[k].mounted) {
				if(!strncmp(jfs[k].name,"/proc/",6)       /* sub directorys have to be fake too */
				       || !strncmp(jfs[k].name,"/sys/",5)
				       || !strncmp(jfs[k].name,"/dev/",5)
				       || !strncmp(jfs[k].name,"/proc",6) /* one more than the string to ensure the NULL */
				       || !strncmp(jfs[k].name,"/sys",5)
				       || !strncmp(jfs[k].name,"/dev",5)
				       || !strncmp(jfs[k].name,"/rpc_pipe",10)
					) { /* /proc gives invalid/insane values */
					mvwprintw(padjfs,2+k, 0, "%-14s", jfs[k].name);
					mvwprintw(padjfs,2+k, 27, "-");
					mvwprintw(padjfs,2+k, 35, "-");
					mvwprintw(padjfs,2+k, 41, "-");
					mvwprintw(padjfs,2+k, 43, "%-8s not a real filesystem",jfs[k].type);
				} else {
					statfs_buffer.f_blocks=0;
				    if((ret=fstatfs( jfs[k].fd, &statfs_buffer)) != -1) {
					if(statfs_buffer.f_blocks != 0) {
					/* older Linux seemed to always report in 4KB blocks but
					   newer Linux release use the f_bsize block sizes but
					   the man statfs docs the field as the natural I/O size so
					   the blocks reported here are ambigous in size */
					if(statfs_buffer.f_bsize == 0) 
						fs_bsize = 4.0 * 1024.0;
					else
						fs_bsize = statfs_buffer.f_bsize;
					/* convery blocks to MB */
					fs_size = (float)statfs_buffer.f_blocks * fs_bsize/1024.0/1024.0;

					/* fine the best size info available f_bavail is like df reports
					   otherwise use f_bsize (this includes inode blocks) */
					if(statfs_buffer.f_bavail == 0) 
						fs_free = (float)statfs_buffer.f_bfree  * fs_bsize/1024.0/1024.0;
					else
						fs_free = (float)statfs_buffer.f_bavail  * fs_bsize/1024.0/1024.0;

					/* this is a percentage */
					fs_size_used = (fs_size - (float)statfs_buffer.f_bfree  * fs_bsize/1024.0/1024.0)/fs_size * 100.0;
					/* try to get the same number as df using kludge */
					fs_size_used += 1.0;
					if (fs_size_used >100.0)
						fs_size_used = 100.0;

					if( (i=strlen(jfs[k].device)) <20)
						str_p=&jfs[k].device[0];
					else {
						str_p=&jfs[k].device[i-20];
					}
				    mvwprintw(padjfs,2+k, 0, "%-20s %7.0f %7.0f %4.0f%% %-8s %s",
					str_p,
					fs_size,
					fs_free,
					fs_size_used,
					jfs[k].type,
					jfs[k].name
					);

					} else {
					mvwprintw(padjfs,2+k, 0, "%s", jfs[k].name);
					mvwprintw(padjfs,2+k, 43, "%-8s size=zero blocks!", jfs[k].type);
					}
				    }
				    else {
					mvwprintw(padjfs,2+k, 0, "%s", jfs[k].name);
					mvwprintw(padjfs,2+k, 43, "%-8s statfs failed", jfs[k].type);
				    }
				}
			    } else {
					mvwprintw(padjfs,2+k, 0, "%-14s", jfs[k].name);
					mvwprintw(padjfs,2+k, 43, "%-8s not mounted",jfs[k].type);
			    }
			}
			DISPLAY(padjfs,2 + jfses);
		    } else {
			jfs_load(LOAD);
			fprintf(fp,show_rrd ? "rrdtool update jfsfile.rrd %s" : "JFSFILE,%s", LOOP);
			for (k = 0; k < jfses; k++) {
			    if(jfs[k].mounted && strncmp(jfs[k].name,"/proc",5)
						&& strncmp(jfs[k].name,"/sys",4)
						&& strncmp(jfs[k].name,"/dev/pts",8)
						&& strncmp(jfs[k].name,"/dev/shm",8)
						&& strncmp(jfs[k].name,"/var/lib/nfs/rpc",16)
				)   { /* /proc gives invalid/insane values */
					    if(fstatfs( jfs[k].fd, &statfs_buffer) != -1) {
					fprintf(fp, show_rrd ? ":%.1f" : ",%.1f",
					((float)statfs_buffer.f_blocks - (float)statfs_buffer.f_bfree)/(float)statfs_buffer.f_blocks*100.0);
				    }
				    else
					fprintf(fp, show_rrd? ":U" : ",0.0");
				}
			}
			fprintf(fp, "\n");
			jfs_load(UNLOAD);
		    }
		}

#endif /* JFS */

		if (show_disk || show_verbose || show_diskmap || show_dgroup) {
                        proc_read(P_STAT);
                        proc_disk(elapsed);
		}
		if (show_diskmap) {
			BANNER(padmap,"Disk %%Busy Map");
			mvwprintw(padmap,0, 18,"Key: @=90 #=80 X=70 8=60 O=50 0=40 o=30 +=20 -=10 .=5 _=0%%");
			mvwprintw(padmap,1, 0,"             Disk No.  1         2         3         4         5         6   ");
			if(disk_first_time) {
				disk_first_time=0;
				mvwprintw(padmap,2, 0,"Please wait - collecting disk data");
			} else {
				mvwprintw(padmap,2, 0,"Disks=%-4d   0123456789012345678901234567890123456789012345678901234567890123", disks);
				mvwprintw(padmap,3, 0,"disk 0 to 63 ");
				for (i = 0; i < disks; i++) {
					disk_busy = DKDELTA(dk_time) / elapsed;
					disk_read = DKDELTA(dk_rkb) / elapsed;
					disk_write = DKDELTA(dk_wkb) / elapsed;
					/* ensure boundaries */
					if (disk_busy <  0)
						disk_busy=0;
					else
						if (disk_busy > 99) disk_busy=99;

#define MAPWRAP 64
					mvwprintw(padmap,3 + (int)(i/MAPWRAP), 13+ (i%MAPWRAP), "%c",disk_busy_map_ch[(int)disk_busy]);
				}
			}
			DISPLAY(padmap,4 + disks/MAPWRAP);
		}
		if(show_verbose) {
			top_disk_busy = 0.0;
			top_disk_name = "";
			for (i = 0,k=0; i < disks; i++) {
				disk_busy = DKDELTA(dk_time) / elapsed;
				if( disk_busy > top_disk_busy) {
					top_disk_busy = disk_busy;
					top_disk_name = p->dk[i].dk_name;
				}
			}
			if(top_disk_busy > 80.0) {
				COLOUR wattrset(padverb,COLOR_PAIR(1));
				mvwprintw(padverb,3, 0, " DANGER");
			}
			else if(top_disk_busy > 60.0) {
				COLOUR wattrset(padverb,COLOR_PAIR(4));
				mvwprintw(padverb,3, 0, "Warning");
			}
			else  {
				COLOUR wattrset(padverb,COLOR_PAIR(2));
				mvwprintw(padverb,3, 0, "     OK");
			}
			COLOUR wattrset(padverb,COLOR_PAIR(0));
			mvwprintw(padverb,3, 8, "-> Top Disk %8s %%busy %5.1f%%\t>40%%\t>60%%          ",top_disk_name,top_disk_busy);
			move(x,0);
		}
		if (show_disk) {
			if (cursed) {
			    if(show_disk) {
				BANNER(paddisk,"Disk I/O");
				switch(disk_mode) {
				case DISK_MODE_PARTITIONS: mvwprintw(paddisk, 0, 12, "/proc/partitions");break;
				case DISK_MODE_DISKSTATS:  mvwprintw(paddisk, 0, 12, "/proc/diskstats");break;
				case DISK_MODE_IO:         mvwprintw(paddisk, 0, 12, "/proc/stat+disk_io");break;
				}
				mvwprintw(paddisk,0, 31, "mostly in KB/s");
				mvwprintw(paddisk,0, 50, "Warning:contains duplicates");
				switch (show_disk) {
				case SHOW_DISK_STATS: 
					mvwprintw(paddisk,1, 0, "DiskName Busy    Read    Write       Xfers   Size  Peak%%  Peak-RW    InFlight ");
					break;
				case SHOW_DISK_GRAPH: 
					mvwprintw(paddisk,1, 0, "DiskName Busy  ");
					COLOUR wattrset(paddisk,COLOR_PAIR(6));
					mvwprintw(paddisk,1, 15, "Read ");
					COLOUR wattrset(paddisk,COLOR_PAIR(3));
					mvwprintw(paddisk,1, 20, "Write");
					COLOUR wattrset(paddisk,COLOR_PAIR(0));
					mvwprintw(paddisk,1, 25, "KB|0          |25         |50          |75       100|");
					break;
				}
			   }
			   if(disk_first_time) { 
				disk_first_time=0;
				mvwprintw(paddisk,2, 0, "Please wait - collecting disk data");
			   } else {
				total_disk_read  = 0.0;
				total_disk_write = 0.0;
				total_disk_xfers = 0.0;
				disk_mb = 0;
				for (i = 0,k=0; i < disks; i++) {
					disk_read = DKDELTA(dk_rkb) / elapsed;
					disk_write = DKDELTA(dk_wkb) / elapsed;
					if((show_disk == SHOW_DISK_GRAPH) && (disk_read > 9999.9 || disk_write > 9999.9)) {
						disk_mb=1;
						COLOUR wattrset(paddisk, COLOR_PAIR(1));
						mvwprintw(paddisk,1, 25, "MB");
						COLOUR wattrset(paddisk, COLOR_PAIR(0));
						break;
					}
				}
				for (i = 0,k=0; i < disks; i++) {
/*
					if(p->dk[i].dk_name[0] == 'h')
						continue;
*/
					disk_busy = DKDELTA(dk_time) / elapsed;
					disk_read = DKDELTA(dk_rkb) / elapsed;
					disk_write = DKDELTA(dk_wkb) / elapsed;
					disk_xfers = DKDELTA(dk_xfers);

					total_disk_read  +=disk_read;
					total_disk_write +=disk_write;
					total_disk_xfers +=disk_xfers;

					if(disk_busy_peak[i] < disk_busy)
						disk_busy_peak[i] = disk_busy;
					if(disk_rate_peak[i] < (disk_read+disk_write))
						disk_rate_peak[i] = disk_read+disk_write;
					if(!show_all && disk_busy < 1)
						continue;

					if(strlen(p->dk[i].dk_name) > 8)
						str_p = &p->dk[i].dk_name[strlen(p->dk[i].dk_name) -8];
					else
						str_p = &p->dk[i].dk_name[0];

					if(show_disk == SHOW_DISK_STATS) {
						/* output disks stats */
						mvwprintw(paddisk,2 + k, 0, "%-8s %3.0f%% %8.1f %8.1fKB/s %6.1f %5.1fKB  %3.0f%% %9.1fKB/s %3d",
						    str_p, 
						    disk_busy,
						    disk_read,
						    disk_write,
						    disk_xfers / elapsed,
						    disk_xfers == 0.0 ? 0.0 : 
						    (DKDELTA(dk_rkb) + DKDELTA(dk_wkb) ) / disk_xfers,
						    disk_busy_peak[i],
						    disk_rate_peak[i],
						    p->dk[i].dk_inflight);
						    k++;
					}
					if(show_disk == SHOW_DISK_GRAPH) {
							/* output disk bar graphs */

	
							if(disk_mb) mvwprintw(paddisk,2 + k, 0, "%-8s %3.0f%% %6.1f %6.1f",
							    str_p, 
								disk_busy,
								disk_read/1024.0,
								disk_write/1024.0);
							else mvwprintw(paddisk,2 + k, 0, "%-8s %3.0f%% %6.1f %6.1f",
							    str_p, 
								disk_busy,
								disk_read,
								disk_write);
							mvwprintw(paddisk,2 + k, 27, "|                                                  ");
							wmove(paddisk,2 + k, 28);
							if(disk_busy >100) disk_busy=100;
							if( disk_busy > 0.0 && (disk_write+disk_read) > 0.1) {
							/* 50 columns in the disk graph area so divide % by two */
							readers = disk_busy*disk_read/(disk_write+disk_read)/2;
							writers = disk_busy*disk_write/(disk_write+disk_read)/2;
							if(readers + writers > 50) {
								readers=0;
								writers=0;
							}
							/* don't go beyond row 78 i.e. j = 28 + 50 */
							for (j = 0; j < readers && j<50; j++) {
								COLOUR wattrset(paddisk,COLOR_PAIR(12));
								wprintw(paddisk,"R");
								COLOUR wattrset(paddisk,COLOR_PAIR(0));
							}
							for (; j < readers + writers && j<50; j++) {
								COLOUR wattrset(paddisk,COLOR_PAIR(11));
								wprintw(paddisk,"W");
								COLOUR wattrset(paddisk,COLOR_PAIR(0));
							}
							for (j = disk_busy; j < 50; j++)
								wprintw(paddisk," ");
							} else {
								for (j = 0; j < 50; j++)
									wprintw(paddisk," ");
								if(p->dk[i].dk_time == 0.0) 
									mvwprintw(paddisk,2 + k, 27, "| disk busy not available");
							     }
							if(disk_busy_peak[i] >100)
							   disk_busy_peak[i]=100;
	
							mvwprintw(paddisk,2 + i, 77, "|");
							/* check rounding has not got the peak ">" over the 100% */
							j = 28+(int)(disk_busy_peak[i]/2);
							if(j>77)
								j=77;
							mvwprintw(paddisk,2 + i, j, ">");
							k++;
					}
				    }
				mvwprintw(paddisk,2 + k, 0, "Totals Read-MB/s=%-8.1f Writes-MB/s=%-8.1f Transfers/sec=%-8.1f",
						    total_disk_read  / 1024.0,
						    total_disk_write / 1024.0,
						    total_disk_xfers / elapsed);

				}
				DISPLAY(paddisk,3 + k);
			} else {
				for (i = 0; i < disks; i++) {
					if(NEWDISKGROUP(i))
						fprintf(fp,show_rrd ? "%srrdtool update diskbusy%s.rrd %s" : "%sDISKBUSY%s,%s",i == 0 ? "": "\n", dskgrp(i), LOOP);
					/* check percentage is correct */
					ftmp = DKDELTA(dk_time) / elapsed;
					if(ftmp > 100.0 || ftmp < 0.0)
						fprintf(fp,show_rrd ? ":U" : ",101.00");
					else
						fprintf(fp,show_rrd ? ":%.1f" : ",%.1f",
							DKDELTA(dk_time) / elapsed);
				}
				for (i = 0; i < disks; i++) {
					if(NEWDISKGROUP(i))
						fprintf(fp,show_rrd ? "\nrrdtool update diskread%s.rrd %s" : "\nDISKREAD%s,%s", dskgrp(i),LOOP);
					fprintf(fp,show_rrd ? ":%.1f" : ",%.1f",
					    DKDELTA(dk_rkb) / elapsed);
				}
				for (i = 0; i < disks; i++) {
					if(NEWDISKGROUP(i))
						fprintf(fp,show_rrd ? "\nrrdtool update diskwrite%s.rrd %s" : "\nDISKWRITE%s,%s", dskgrp(i),LOOP);
					fprintf(fp,show_rrd ? ":%.1f" : ",%.1f",
					    DKDELTA(dk_wkb) / elapsed);
				}
				for (i = 0; i < disks; i++) {
					if(NEWDISKGROUP(i))
						fprintf(fp,show_rrd ? "\nrrdtool update diskxfer%s.rrd %s" : "\nDISKXFER%s,%s", dskgrp(i),LOOP);
					disk_xfers = DKDELTA(dk_xfers);
					fprintf(fp,show_rrd ? ":%.1f" : ",%.1f",
						    disk_xfers / elapsed);
				}
				for (i = 0; i < disks; i++) {
					if(NEWDISKGROUP(i))
						fprintf(fp,show_rrd ? "\nrrdtool update diskbsize%s.rrd %s" : "\nDISKBSIZE%s,%s", dskgrp(i),LOOP);
					disk_xfers = DKDELTA(dk_xfers);
					fprintf(fp,show_rrd ? ":%.1f" : ",%.1f",
						    disk_xfers == 0.0 ? 0.0 :
						    (DKDELTA(dk_rkb) + DKDELTA(dk_wkb) ) / disk_xfers);
				}

				if( extended_disk == 1 && disk_mode == DISK_MODE_DISKSTATS )	{
					for (i = 0; i < disks; i++) {
						if(NEWDISKGROUP(i))	{
							fprintf(fp,"\nDISKREADS%s,%s", dskgrp(i),LOOP);
						}
						disk_read = DKDELTA(dk_reads);
						fprintf(fp,",%.1f", disk_read / elapsed);
					}

					for (i = 0; i < disks; i++) {
						if(NEWDISKGROUP(i))	{
							fprintf(fp,"\nDISKWRITES%s,%s", dskgrp(i),LOOP);
						}
						disk_write = DKDELTA(dk_writes);
						fprintf(fp,",%.1f", disk_write / elapsed);
					}
				}
				fprintf(fp,"\n");
			}
		}
		if ((show_dgroup || (!cursed && dgroup_loaded))) {
			if (cursed) {
				BANNER(paddg,"Disk-Group-I/O");
				if (dgroup_loaded != 2 || dgroup_total_disks == 0) {
					mvwprintw(paddg, 1, 1, "No Disk Groups found use -g groupfile when starting nmon");
					n = 0;
				} else if (disk_first_time) {
					disk_first_time=0;
					mvwprintw(paddg, 1, 1, "Please wait - collecting disk data");
				} else {
					mvwprintw(paddg, 1, 1, "Name          Disks AvgBusy Read|Write-KB/s  TotalMB/s   xfers/s BlockSizeKB");
					total_busy   = 0.0;
					total_rbytes = 0.0;
					total_wbytes = 0.0;
					total_xfers  = 0.0;
					for(k = n = 0; k < dgroup_total_groups; k++) {
/*
						if (dgroup_name[k] == 0 )
							continue;
*/
						disk_busy   = 0.0;
						disk_read = 0.0;
						disk_write = 0.0;
						disk_xfers  = 0.0;
						for (j = 0; j < dgroup_disks[k]; j++) {
							i = dgroup_data[k*DGROUPITEMS+j];
							if (i != -1) {
								disk_busy   += DKDELTA(dk_time) / elapsed;
/*
								disk_read += DKDELTA(dk_reads) * p->dk[i].dk_bsize / 1024.0 /elapsed;
								disk_write += DKDELTA(dk_writes) * p->dk[i].dk_bsize / 1024.0 /elapsed;
*/
								disk_read += DKDELTA(dk_rkb) /elapsed;
								disk_write += DKDELTA(dk_wkb) /elapsed;
								disk_xfers  += DKDELTA(dk_xfers) /elapsed;
							}
						}
						if (dgroup_disks[k] == 0)
							disk_busy = 0.0;
						else
							disk_busy = disk_busy / dgroup_disks[k];
						total_busy += disk_busy;
						total_rbytes += disk_read;
						total_wbytes += disk_write;
						total_xfers  += disk_xfers;
/*						if (!show_all && (disk_read < 1.0 && disk_write < 1.0))
							continue;
*/
						if ((disk_read + disk_write) == 0 || disk_xfers == 0)
							disk_size = 0.0;
						else
							disk_size = ((float)disk_read + (float)disk_write) / (float)disk_xfers;
						mvwprintw(paddg, n + 2, 1, "%-14s   %3d %5.1f%% %9.1f|%-9.1f %6.1f %9.1f %6.1f ",
							 dgroup_name[k], 
							 dgroup_disks[k],
							 disk_busy,
							 disk_read,
							 disk_write,
							 (disk_read + disk_write) / 1024, /* in MB */
							 disk_xfers,
							 disk_size
							 );
						n++;
					}
					mvwprintw(paddg, n + 2, 1, "Groups=%2d TOTALS %3d %5.1f%% %9.1f|%-9.1f %6.1f %9.1f",
						 n,
						 dgroup_total_disks,
						 total_busy / dgroup_total_disks,
						 total_rbytes,
						 total_wbytes,
						 (((double)total_rbytes + (double)total_wbytes)) / 1024, /* in MB */
						 total_xfers
						 );
				}
				DISPLAY(paddg, 3 + dgroup_total_groups);
			} else {
				if (dgroup_loaded == 2) {
					fprintf(fp, show_rrd ? "rrdtool update dgbusy.rdd %s" : "DGBUSY,%s", LOOP);
					for (k = 0; k < dgroup_total_groups; k++) {
						if (dgroup_name[k] != 0) {
							disk_total = 0.0;
							for (j = 0; j < dgroup_disks[k]; j++) {
								i = dgroup_data[k*DGROUPITEMS+j];
								if (i != -1) {
									disk_total += DKDELTA(dk_time) / elapsed;
								}
							}
							fprintf(fp, show_rrd ? ":%.1f" : ",%.1f", (float)(disk_total / dgroup_disks[k]));
						}
					}
					fprintf(fp, "\n");
					fprintf(fp, show_rrd ? "rrdtool update dgread.rdd %s" : "DGREAD,%s", LOOP);
					for (k = 0; k < dgroup_total_groups; k++) {
						if (dgroup_name[k] != 0) {
							disk_total = 0.0;
							for (j = 0; j < dgroup_disks[k]; j++) {
								i = dgroup_data[k*DGROUPITEMS+j];
								if (i != -1) {
/*
									disk_total += DKDELTA(dk_reads) * p->dk[i].dk_bsize / 1024.0;
*/
									disk_total += DKDELTA(dk_rkb);
								}
							}
							fprintf(fp, show_rrd ? ":%.1f" : ",%.1f", disk_total / elapsed);
						}
					}
					fprintf(fp, "\n");
					fprintf(fp, show_rrd ? "rrdtool update dgwrite.rdd %s" : "DGWRITE,%s", LOOP);
					for (k = 0; k < dgroup_total_groups; k++) {
						if (dgroup_name[k] != 0) {
							disk_total = 0.0;
							for (j = 0; j < dgroup_disks[k]; j++) {
								i = dgroup_data[k*DGROUPITEMS+j];
								if (i != -1) {
/*
									disk_total += DKDELTA(dk_writes) * p->dk[i].dk_bsize / 1024.0;
*/
									disk_total += DKDELTA(dk_wkb);
								}
							}
							fprintf(fp, show_rrd ? ":%.1f" : ",%.1f", disk_total / elapsed);
						}
					}
					fprintf(fp, "\n");
					fprintf(fp, show_rrd ? "rrdtool update dgbsize.rdd %s" : "DGSIZE,%s", LOOP);
					for (k = 0; k < dgroup_total_groups; k++) {
						if (dgroup_name[k] != 0) {
							disk_write = 0.0;
							disk_xfers  = 0.0;
							for (j = 0; j < dgroup_disks[k]; j++) {
								i = dgroup_data[k*DGROUPITEMS+j];
								if (i != -1) {
/*
									disk_write += (DKDELTA(dk_reads) + DKDELTA(dk_writes) ) * p->dk[i].dk_bsize / 1024.0;
*/
									disk_write += (DKDELTA(dk_rkb) + DKDELTA(dk_wkb) );
									disk_xfers  += DKDELTA(dk_xfers);
								}
							}
							if ( disk_write == 0.0 || disk_xfers == 0.0)
								disk_size = 0.0;
							else
								disk_size = disk_write / disk_xfers;
							fprintf(fp, show_rrd ? ":%.1f" : ",%.1f", disk_size);
						}
					}
					fprintf(fp, "\n");
					fprintf(fp, show_rrd ? "rrdtool update dgxfer.rdd %s" : "DGXFER,%s", LOOP);
					for (k = 0; k < dgroup_total_groups; k++) {
						if (dgroup_name[k] != 0) {
							disk_total = 0.0;
							for (j = 0; j < dgroup_disks[k]; j++) {
								i = dgroup_data[k*DGROUPITEMS+j];
								if (i != -1) {
									disk_total  += DKDELTA(dk_xfers);
								}
							}
							fprintf(fp, show_rrd ? ":%.1f" : ",%.1f", disk_total / elapsed);
						}
					}
					fprintf(fp, "\n");

					if( extended_disk == 1 && disk_mode == DISK_MODE_DISKSTATS )	{
						fprintf(fp,"DGREADS,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_reads);
									}
								}
								fprintf(fp,",%.1f", disk_total / elapsed);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGREADMERGE,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_rmerge);
									}
								}
								fprintf(fp,",%.1f", disk_total / elapsed);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGREADSERV,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_rmsec);
									}
								}
								fprintf(fp,",%.1f", disk_total);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGWRITES,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_writes);
									}
								}
								fprintf(fp,",%.1f", disk_total / elapsed);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGWRITEMERGE,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_wmerge);
									}
								}
								fprintf(fp,",%.1f", disk_total / elapsed);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGWRITESERV,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_wmsec);
									}
								}
								fprintf(fp,",%.1f", disk_total);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGINFLIGHT,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += p->dk[i].dk_inflight;
									}
								}
								fprintf(fp,",%.1f", disk_total);
							}
						}
						fprintf(fp, "\n");
						fprintf(fp,"DGIOTIME,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_time);
									}
								}
								fprintf(fp,",%.1f", disk_total);
							}
						}
						fprintf(fp, "\n");
#ifdef EXPERIMENTAL
						fprintf(fp,"DGF11,%s", LOOP);
						for (k = 0; k < dgroup_total_groups; k++) {
							if (dgroup_name[k] != 0) {
								disk_total = 0.0;
								for (j = 0; j < dgroup_disks[k]; j++) {
									i = dgroup_data[k*DGROUPITEMS+j];
									if (i != -1) {
										disk_total  += DKDELTA(dk_11);
									}
								}
								fprintf(fp,",%.1f", disk_total);
							}
						}
						fprintf(fp, "\n");
#endif /*EXPERIMENTAL*/
					} /* if( extended_disk == 1 && disk_mode == DISK_MODE_DISKSTATS */
				}	/* if (dgroup_loaded == 2) */
			}	/* else from if(cursed) */
		}	/* 		if ((show_dgroup || (!cursed && dgroup_loaded))) { */

		if (show_top) {
			/* Get the details of the running processes */
			firstproc = 0;
			skipped = 0;
			n = getprocs(0);
			if (n > p->nprocs) {
				n = n +128; /* allow for growth in the number of processes in the mean time */
				p->procs = realloc(p->procs, sizeof(struct procsinfo ) * (n+1) ); /* add one to avoid overrun */
				p->nprocs = n;
			}

			firstproc = 0;
                        n = getprocs(1);

			if (topper_size < n) {
				topper = realloc(topper, sizeof(struct topper ) * (n+1) ); /* add one to avoid overrun */
				topper_size = n;
			}
			/* Sort the processes by CPU utilisation */
			for ( i = 0, max_sorted = 0; i < n; i++) {
				/* move forward in the previous array to find a match*/
				for(j=0;j < q->nprocs;j++) {
				    if (p->procs[i].pi_pid == q->procs[j].pi_pid) { /* found a match */
					topper[max_sorted].index = i;
					topper[max_sorted].other = j;
					topper[max_sorted].time =  TIMEDELTA(pi_utime,i,j) + 
								   TIMEDELTA(pi_stime,i,j);
					topper[max_sorted].size =  p->procs[i].statm_resident;

					max_sorted++;
					break;
				    }
				}
			}
			switch(show_topmode) {
			default:
			case 3: qsort((void *) & topper[0], max_sorted, sizeof(struct topper ), &cpu_compare );
				break;
			case 4: qsort((void *) & topper[0], max_sorted, sizeof(struct topper ), &size_compare );
				break;
#ifdef DISK
			case 5: qsort((void *) & topper[0], max_sorted, sizeof(struct topper ), &disk_compare );
				break;
#endif /* DISK */
			}
			CURSE BANNER(padtop,"Top Processes");
			CURSE mvwprintw(padtop,0, 15, "Procs=%d mode=%d (1=Basic, 3=Perf 4=Size 5=I/O)", n, show_topmode);
			if(cursed && top_first_time) {
				top_first_time = 0;
				mvwprintw(padtop,1, 1, "Please wait - information being collected");
			}
			else {
			switch (show_topmode) {
			case 1:
				CURSE mvwprintw(padtop,1, 1, "  PID      PPID  Pgrp Nice Prior Status    proc-Flag Command");
				for (j = 0; j < max_sorted; j++) {
					i = topper[j].index;
					if (p->procs[i].pi_pgrp == p->procs[i].pi_pid)
						strcpy(pgrp, "none");
					else
						sprintf(&pgrp[0], "%d", p->procs[i].pi_pgrp);
					/* skip over processes with 0 CPU */
					if(!show_all && (topper[j].time/elapsed < ignore_procdisk_threshold) && !cmdfound) 
						break;
					    if( x + j + 2 - skipped > LINES+2) /* +2 to for safety :-) */
						break;
					CURSE mvwprintw(padtop,j + 2 - skipped, 1, "%7d %7d %6s %4d %4d %9s 0x%08x %1s %-32s",
					    p->procs[i].pi_pid,
					    p->procs[i].pi_ppid,
					    pgrp,
					    p->procs[i].pi_nice,
					    p->procs[i].pi_pri,

					    (topper[j].time * 100 / elapsed) ? "Running "
					     : get_state(p->procs[i].pi_state),
					    p->procs[i].pi_flags,
					    (p->procs[i].pi_tty_nr ? "F" : " "),
					    p->procs[i].pi_comm);
				}
				break;
			case 3:
			case 4:
			case 5:

				if(show_args == ARGS_ONLY) 
					formatstring = "  PID    %%CPU ResSize    Command                                            ";

				else if(COLS > 119)
					formatstring = "  PID       %%CPU    Size     Res    Res     Res     Res    Shared    Faults  Command";
				else
					formatstring = "  PID    %%CPU  Size   Res   Res   Res   Res Shared   Faults Command";
				CURSE mvwprintw(padtop,1, y, formatstring);

				if(show_args == ARGS_ONLY)
					formatstring = "         Used      KB                                                        ";
				else if(COLS > 119)
					formatstring = "            Used      KB     Set    Text    Data     Lib    KB     Min   Maj";
				else
					formatstring = "         Used    KB   Set  Text  Data   Lib    KB  Min  Maj ";
				CURSE mvwprintw(padtop,2, 1, formatstring);
				for (j = 0; j < max_sorted; j++) {
					i = topper[j].index;
					if(!show_all) { 
							/* skip processes with zero CPU/io */
						if(show_topmode == 3 && (topper[j].time/elapsed) < ignore_procdisk_threshold && !cmdfound)
							break;
						if(show_topmode == 5 && (topper[j].io < ignore_io_threshold && !cmdfound))
							break;
					}
					if(cursed) {
					    if( x + j + 3 - skipped > LINES+2) /* +2 to for safety :-) */
						break;
					    if(cmdfound && !cmdcheck(p->procs[i].pi_comm)) {
						skipped++;
					    	continue;
					    }
					  if(show_args == ARGS_ONLY){
					    mvwprintw(padtop,j + 3 - skipped, 1, 
					    "%7d %5.1f %7lu %-120s",
					    p->procs[i].pi_pid,
					    topper[j].time / elapsed,
					    p->procs[i].statm_resident*pagesize/1024, /* in KB */
					    args_lookup(p->procs[i].pi_pid,
							p->procs[i].pi_comm));
					  }
					  else {
					if(COLS > 119)
					    formatstring = "%8d %7.1f %7lu %7lu %7lu %7lu %7lu %5lu %6d %6d %-32s";
					else
					    formatstring = "%7d %5.1f %5lu %5lu %5lu %5lu %5lu %5lu %4d %4d %-32s";
					    mvwprintw(padtop,j + 3 - skipped, 1, formatstring,
					    p->procs[i].pi_pid,
					    topper[j].time/elapsed,
	/* topper[j].time /1000.0 / elapsed,*/
					    p->procs[i].statm_size*pagesize/1024UL, /* in KB */
					    p->procs[i].statm_resident*pagesize/1024UL, /* in KB */
					    p->procs[i].statm_trs*pagesize/1024UL, /* in KB */
					    p->procs[i].statm_drs*pagesize/1024UL, /* in KB */
					    p->procs[i].statm_lrs*pagesize/1024UL, /* in KB */
					    p->procs[i].statm_share*pagesize/1024UL, /* in KB */
					    (int)(COUNTDELTA(pi_minflt) / elapsed),
					    (int)(COUNTDELTA(pi_majflt) / elapsed),
					    p->procs[i].pi_comm);
					  }
					}
					else {
					    if((cmdfound && cmdcheck(p->procs[i].pi_comm)) || 
						(!cmdfound && ((topper[j].time / elapsed) > ignore_procdisk_threshold)) )
						 {
#ifndef KERNEL_2_6_18
					   	fprintf(fp,"TOP,%07d,%s,%.2f,%.2f,%.2f,%lu,%lu,%lu,%lu,%lu,%d,%d,%s\n",
#else
					   	fprintf(fp,"TOP,%07d,%s,%.2f,%.2f,%.2f,%lu,%lu,%lu,%lu,%lu,%d,%d,%s,%ld,%llu\n",
#endif
					    /* 1 */ p->procs[i].pi_pid,
					    /* 2 */ LOOP,
					    /* 3 */ topper[j].time / elapsed,
                                            /* 4 */ TIMEDELTA(pi_utime,i,topper[j].other) / elapsed,
                                            /* 5 */ TIMEDELTA(pi_stime,i,topper[j].other) / elapsed,
					    /* 6 */ p->procs[i].statm_size*pagesize/1024UL, /* in KB */
					    /* 7 */ p->procs[i].statm_resident*pagesize/1024UL, /* in KB */
					    /* 8 */ p->procs[i].statm_trs*pagesize/1024UL, /* in KB */
					    /* 9 */ p->procs[i].statm_drs*pagesize/1024UL, /* in KB */
					    /* 10*/ p->procs[i].statm_share*pagesize/1024UL, /* in KB */
					    /* 11*/ (int)(COUNTDELTA(pi_minflt) / elapsed),
					    /* 12*/ (int)(COUNTDELTA(pi_majflt) / elapsed),
					    /* 13*/ p->procs[i].pi_comm

#ifndef KERNEL_2_6_18
					   	);
#else

					    ,
					    p->procs[i].pi_num_threads,
					    COUNTDELTA(pi_delayacct_blkio_ticks)
					   	);
#endif

					    if(show_args)
						args_output(p->procs[i].pi_pid,loop, p->procs[i].pi_comm);

					    } else skipped++;
					}
				}
				break;
			    }
			}
			CURSE DISPLAY(padtop,j + 3);
		}

		if(cursed) {
			if(show_verbose) {
				y=x;
				x=1;
				DISPLAY(padverb,4);
				x=y;
			}
			if(x<LINES-2)mvwhline(stdscr, x, 1, ACS_HLINE,COLS-2);
			wmove(stdscr,0, 0);
			wrefresh(stdscr);
			doupdate();

			for (i = 0; i < seconds; i++) {
				sleep(1);
				if (checkinput())
					break;
			}
		}
		else {
			fflush(NULL);
			secs = seconds; 
redo:
			errno = 0;
			ret = sleep(secs); 
			if( (ret != 0 || errno != 0) && loop != maxloops ) {
				fprintf(fp,"ERROR,%s,sleep got interrupted:",LOOP);
				fprintf(fp,"ret was %d, ",ret);
				fprintf(fp,"errno was %d\n",errno);
				secs=ret;
				goto redo;
			}
		}

		switcher();

		if (loop >= maxloops) {
			CURSE endwin();
                        if (nmon_end) {
                                child_start(CHLD_END, nmon_end, time_stamp_type, loop, timer);
                                /* Give the end - processing some time - 5s for now */
                                sleep(5);
                        }

			fflush(NULL);
			exit(0);
		}
	}
}
