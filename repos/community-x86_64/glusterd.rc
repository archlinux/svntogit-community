#!/bin/sh
# Thanks to igor

. /etc/rc.conf
. /etc/rc.d/functions

PID="/var/run/glusterd.pid"

case "$1" in
    start)
        stat_busy "Starting glusterd"
        /usr/sbin/glusterd -p $PID &>/dev/null
        if [ $? -gt 0 ]; then
            stat_fail
        else
            add_daemon glusterd
            stat_done
        fi
    ;;
    stop)
        stat_busy "Stopping glusterd"
        kill -QUIT `cat "$PID"` &>/dev/null
        if [ $? -ne 0 ]; then
            stat_fail
        else
            rm_daemon glusterd
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
esac

exit 0
