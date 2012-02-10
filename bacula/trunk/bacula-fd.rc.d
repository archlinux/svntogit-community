#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PIDFILE=/var/run/bacula/bacula-fd.*.pid
PID=$(cat $PIDFILE 2>/dev/null)

case "$1" in
  start)

    [ -d /var/run/bacula ] || mkdir -p /var/run/bacula
	chown bacula:bacula /var/run/bacula

    stat_busy "Starting Bacula File Daemon"
    /usr/sbin/bacula-fd
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon bacula-fd
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Bacula File Daemon"
    kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon bacula-fd
      rm $PIDFILE &> /dev/null
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
