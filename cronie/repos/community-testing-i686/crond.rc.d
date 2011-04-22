#!/bin/bash

### /etc/rc.d/crond: Initscript for Cron Daemon

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/sbin/crond`
case "$1" in
  start)
    stat_busy "Starting Cron Daemon"
    [ -d /var/spool/anacron ] ||
      install -dm755 /var/spool/anacron
    [ -z "$PID" ] && \
      /usr/sbin/crond &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else stat_done; add_daemon crond
      echo $PID > /var/run/crond.pid
    fi ;;
  stop)
    stat_busy "Stopping Cron Daemon"
    [ ! -z "$PID" ] \
      && kill $PID &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      stat_done; rm_daemon crond
    fi ;;
  restart)
    $0 stop
    sleep 1
    $0 start ;;
  *)
    echo "usage: $0 {start|stop|restart}"  
esac

exit 0

### /etc/rc.d/crond: Initscript for Cron Daemon
