#!/bin/bash
#
# GNU Zebra Routing Manager/RIP/RIPng/OSPF/OSPF6/BGPD4 start/stop script
#
# based on AUR/community/quagga 0.99.1-1 port template script
# by shild, shildv at gmail dot com
#

DNAME="ospfd"
PORT="2604"

PID="`pidof -o %PPID /usr/sbin/$DNAME`"

. /etc/rc.conf
. /etc/rc.d/functions

. /etc/conf.d/quagga

case $1 in
    start)
	stat_busy "Starting Quagga $DNAME daemon"
	
	if [ -z "$PID" -a -f /etc/quagga.d/$DNAME.conf ]
	then
	    /usr/sbin/$DNAME -d \
			    -f /etc/quagga.d/$DNAME.conf \
			    -i /var/run/quagga/$DNAME.pid \
			    -A 127.0.0.1 \
			    -P $PORT \
			    -u quagga \
			    -g quagga
	    
	    if [ $cpulimit_ospfd = 1 ]
            then
		/usr/bin/cpulimit -P /usr/sbin/$DNAME -l $ospfd_cpu -z \
		    > /dev/null 2> /dev/null &
	    fi
	
	    sleep 1; # Wait for forking (PID changes)
	    
	    PID="`pidof -o %PPID /usr/sbin/$DNAME`"
	    if [ -z "$PID" ]
	    then
        	stat_fail
	    else
	        add_daemon $DNAME
                stat_done
            fi
	
	else
    	    stat_fail
        fi
	;;
    stop)
	stat_busy "Stopping Quagga $DNAME daemon"
    
        [ ! -z "$PID" ] && kill "$PID" &> /dev/null
	
	if [ $? -gt 0 ]
	then
	    stat_fail
	else
	    rm_daemon $DNAME
	    stat_done
	fi
	
	sleep 1
	;;
  restart)
	$0 stop
	sleep 1
	$0 start
	;;
  *)
	echo "usage: $0 [start|stop|restart]"
esac

exit 0

# EOF

