#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/sbin/chronyd`
case "$1" in
  start)
    stat_busy "Starting chrony Daemon"
    if [ -z "$PID" ]; then 
       /usr/sbin/chronyd $NTPD_ARGS &
    fi
    if [ ! -z "$PID" -o $? -gt 0 ]; then
      stat_fail
    else
      add_daemon chrony
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping chrony Daemon"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon chrony
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
