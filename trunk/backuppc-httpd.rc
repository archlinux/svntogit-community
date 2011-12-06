#!/bin/bash

# general config
. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)
    stat_busy "Starting BackupPC HTTP Daemon"
      /usr/sbin/apachectl -f /etc/httpd/conf/backuppc-httpd.conf -k start
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon backuppc-httpd
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping BackupPC HTTP Daemon"
    /usr/sbin/apachectl -f /etc/httpd/conf/backuppc-httpd.conf -k stop
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon backuppc-httpd
      stat_done
    fi
    ;;
  restart)
    $0 stop
    sleep 3
    $0 start
    ;;
  reload)
    if [ -f /var/run/backuppc-httpd.pid ]; then
      status "Reloading BackupPC HTTP Configuration" kill -HUP `cat /var/run/backuppc-httpd.pid`
    fi
    ;;
  *)
    echo "usage: $0 {start|stop|restart|reload}"  
esac
