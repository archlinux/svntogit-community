#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/sbin/igmpproxy`
case "$1" in
  start)
    stat_busy "Starting igmpproxy routing daemon"
    if [ -z "$PID" ]; then 
       /usr/sbin/igmpproxy /etc/igmpproxy.conf &
    fi
    if [ ! -z "$PID" -o $? -gt 0 ]; then
      stat_fail
    else
      disown
      add_daemon igmpproxy
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping igmpproxy routing daemon"
    [ ! -z "$PID" ] && kill $PID &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon igmpproxy
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
