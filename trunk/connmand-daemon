#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

DESC="Connection Manager"
NAME="connmand"
ARGS=""
DAEMON="/usr/sbin/$NAME"

PID=`pidof -o %PPID ${DAEMON}`
case "$1" in
  start)
    stat_busy "Starting ${DESC}"
    if [ -z "$PID" ]; then
       ${DAEMON} ${ARGS}
    fi
    if [ ! -z "$PID" -o $? -gt 0 ]; then
      stat_fail
    else
      add_daemon ${NAME}
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping ${DESC}"
    [ ! -z "$PID" ]  && killall ${DAEMON} &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon ${NAME}
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
