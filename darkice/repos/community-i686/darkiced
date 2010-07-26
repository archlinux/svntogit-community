#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/bin/darkice`
case "$1" in
  start)
    stat_busy "Starting Darkice"
    [ -z "$PID" ] && /usr/bin/darkice &>/dev/null &
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon darkice
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Darkice"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon darkice
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
