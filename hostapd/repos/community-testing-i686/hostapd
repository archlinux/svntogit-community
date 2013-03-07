#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/hostapd

case "$1" in
  start)
    stat_busy "Starting hostapd"
    /usr/bin/hostapd -B -P ${HOSTAPD_PID} ${HOSTAPD_CONF} &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      stat_done
      add_daemon hostapd
    fi
    ;;
  stop)
    stat_busy "Stopping hostapd"
    [ -f ${HOSTAPD_PID} ] && kill `cat ${HOSTAPD_PID}` &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      stat_done
      rm_daemon hostapd
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
