#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)
    stat_busy "Loading IPSec Security Policy Database..."
    /usr/sbin/setkey -f /etc/ipsec.conf &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon ipsec
      stat_done
    fi
    ;;
  stop)
    stat_busy "Unloading IPSec Security Policy Database..."
    /usr/sbin/setkey -F -P
    /usr/sbin/setkey -F
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon ipsec
      stat_done
    fi
    ;;
  restart)
    $0 stop
    $0 start
    ;;
  *)
    echo "usage: $0 {start|stop|restart}"
esac
exit 0
