#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)
    stat_busy "Starting multipathd"
    /usr/bin/multipathd
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon multipathd
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping multipathd"
    [ -f /var/run/multipathd.pid ] && kill `cat /var/run/multipathd.pid` >/dev/null 2>&1 
      if [ $? -gt 0 ]; then
        stat_fail
      else
        rm_daemon multipathd
        stat_done
      fi 
      ;;
  restart)
    $0 stop
    sleep 2
    $0 start
    ;;
  *)
    echo "usage: $0 {start|stop|restart}"  
esac
exit 0
