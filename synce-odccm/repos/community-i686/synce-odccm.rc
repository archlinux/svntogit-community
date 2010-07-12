#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
    start)
        stat_busy "Starting SynCE odccm daemon"
        /usr/sbin/odccm >/dev/null 2>/dev/null
        if [ $? -gt 0 ]; then
            stat_fail
        else
            add_daemon synce-odccm
            stat_done
        fi
        ;;
    stop)
        stat_busy "Stopping SynCE odccm daemon"
	PID=`pidof odccm`
        if [ -z $PID ]; then
            stat_fail
        else
	    kill $PID
            rm_daemon synce-odccm
            stat_done
        fi
        ;;
    restart)
        $0 stop
	sleep 1
        $0 start
        ;;
    *)
        echo "usage: $0 {start|stop|restart}"
	;;
esac
exit 0
