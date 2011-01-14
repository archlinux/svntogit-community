#!/bin/bash
. /etc/rc.conf
. /etc/rc.d/functions

DAEMON=polipo
ARGS="daemonise=true pidFile=/var/run/$DAEMON/$DAEMON.pid"
PID=$(pidof -o %PPID /usr/bin/$DAEMON)

case $1 in
    start)
        stat_busy "Starting $DAEMON"
        if ck_daemon $DAEMON; then
            [[ ! -d /var/run/$DAEMON ]] && install -d $DAEMON /var/run/$DAEMON
            /usr/bin/$DAEMON $ARGS >/dev/null 2>&1
            if [[ $? != 0 ]]; then
                stat_fail
            else
                add_daemon polipo
                stat_done
            fi
        else
            stat_fail
        fi
    ;;
    stop)
        stat_busy "Stopping $DAEMON"
        if ! ck_daemon $DAEMON; then
            kill $PID >/dev/null 2>&1
            if [[ $? != 0 ]]; then
                stat_fail
            else
                rm_daemon $DAEMON
                stat_done
            fi
        else
            stat_fail
        fi
    ;;
    purge)
        stat_busy "Purging $DAEMON"
        [[ ! -d /var/run/$DAEMON ]] && install -d $DAEMON /var/run/$DAEMON
        if ! ck_daemon $DAEMON; then
            kill -USR1 $PID >/dev/null 2>&1
            sleep 1
            /usr/bin/$DAEMON -x $ARGS >/dev/null 2>&1 || stat_fail
            kill -USR2 $PID >/dev/null 2>&1
            stat_done
        else
            /usr/bin/$DAEMON -x $ARGS >/dev/null 2>&1 || stat_fail
            stat_done
        fi
    ;;
    restart)
        $0 stop
        $0 start
    ;;
    *)
        echo "usage: $0 {start|stop|restart|purge}"
    ;;
esac
