#!/bin/bash

### /etc/rc.d/radvd: Initscript for radvd Daemon

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/sbin/radvd`
case "$1" in
  start)
    stat_busy "Starting radvd Daemon"
    [ -z "$PID" ] && \
      /usr/sbin/radvd &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else stat_done; add_daemon radvd
      echo $PID > /var/run/radvd.pid
    fi ;;
  stop)
    stat_busy "Stopping radvd Daemon"
    [ ! -z "$PID" ] \
      && kill $PID &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      stat_done; rm_daemon radvd
    fi ;;
  restart)
    $0 stop
    sleep 1
    $0 start ;;
  *)
    echo "usage: $0 {start|stop|restart}"
esac

exit 0

### /etc/rc.d/radvd: Initscript for radvd Daemon
