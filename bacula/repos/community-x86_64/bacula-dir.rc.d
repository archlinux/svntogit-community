#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)

    [ -d /var/run/bacula ] || mkdir -p /var/run/bacula
	chown bacula:bacula /var/run/bacula

    stat_busy "Starting Bacula Director Daemon"
    /usr/sbin/bacula-dir
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon bacula-dir
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Bacula Director Daemon"
    killall bacula-dir > /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon bacula-dir
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
