#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

FERM="/usr/sbin/ferm"

[[ -f /etc/conf.d/ferm ]] && . /etc/conf.d/ferm

case "$1" in
  start)
    stat_busy "Starting ferm"
    $FERM $FERM_ARGS $FERM_CONFIG
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon ferm
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping ferm"
    $FERM -F $FERM_ARGS $FERM_CONFIG
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon ferm      
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

# vim:set ts=2 sw=2 ft=sh et:
