#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

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
    killall bacula-fd > /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon bacula-fd
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
