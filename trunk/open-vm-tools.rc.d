#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

# source application-specific settings
[ -f /etc/conf.d/open-vm-tools ] && . /etc/conf.d/open-vm-tools

PID=`pidof -o %PPID /usr/bin/vmtoolsd`
case "$1" in
  start)
    stat_busy "Starting Open Virtual Machine Tools"

    if [ "$VM_DRAG_AND_DROP" == "yes" ]; then
	VMBLOCK=`grep -w vmblock /proc/modules`
	[ -z "$VMBLOCK" ] && modprobe vmblock
	if [ $? -gt 0 ]; then
    	    stat_fail
	    exit 1
	fi
	
	DND_TMPDIR="/tmp/VMwareDnD"
	if [ ! -d "$DND_TMPDIR" ]; then
	    mkdir $DND_TMPDIR
	    chmod 1777 $DND_TMPDIR
	fi
	
	mount -t vmblock none /proc/fs/vmblock/mountPoint
	if [ $? -gt 0 ]; then
    	    stat_fail
	    exit 1
	fi
    fi


    for m in vmhgfs vmsync; do
	VMMOD=`grep -w $m /proc/modules`
	[ -z "$VMMOD" ] && \
		{ modprobe $m
		if [ $? -gt 0 ]; then
		    stat_fail
		    exit 1
		fi; }
    done


    [ -z "$PID" ] && /usr/bin/vmtoolsd --background $PIDFILE
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon open-vm-tools
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Open Virtual Machine Tools"
    [ ! -z "$PID" ]  && kill $PID &>/dev/null
#    if [ $? -gt 0 ]; then
#      stat_fail
#      exit 1
#    fi

    for m in vmhgfs vmsync vmci; do
	VMMOD=`grep -w $m /proc/modules`
	[ ! -z "$VMMOD" ] && rmmod $m
	if [ $? -gt 0 ]; then
	  stat_fail
	  exit 4
	fi
    done

    if [ "$VM_DRAG_AND_DROP" == "yes" ]; then
	MOUNTPOINT=`grep -w "none /proc/fs/vmblock/mountPoint vmblock" /proc/modules`
	[ -z "$MOUNTPOINT" ] && umount /proc/fs/vmblock/mountPoint
        if [ $? -gt 0 ]; then
	  stat_fail
    	  exit 5
	fi
	
	DND_TMPDIR="/tmp/VMwareDnD"
	rm -r $DND_TMPDIR
	
	VMBLOCK=`grep -w vmblock /proc/modules`
	[ ! -z "$VMBLOCK" ] && rmmod vmblock
        if [ $? -gt 0 ]; then
	  stat_fail
    	  exit 6
	fi
    fi
        
    rm_daemon open-vm-tools
    stat_done
    ;;
  restart)
    $0 stop
    $0 start
    ;;
  *)
    echo "usage: $0 {start|stop|restart}"  
esac
exit 0
