#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)

    [ -d /var/run/bacula ] || mkdir -p /var/run/bacula
	chown bacula:bacula /var/run/bacula

    stat_busy "Starting Bacula Storage Daemon"
    /usr/sbin/bacula-sd
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon bacula-sd
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Bacula Storage Daemon"
    killall bacula-sd > /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon bacula-sd
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
~                                                                                                                                                         
~         
