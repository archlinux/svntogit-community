#!/bin/bash

CONF=/etc/conf.d/murmur

. /etc/rc.conf
. /etc/rc.d/functions

[ -f $CONF ] && . $CONF

PID=$(pidof -o %PPID /usr/sbin/murmurd)
case "$1" in
  start)
    stat_busy "Starting murmur"

    [ -d /var/run/murmur ] || mkdir -p /var/run/murmur
    chown murmur:murmur /var/run/murmur

    [ -z "$PID" ] && /usr/sbin/murmurd $PARAMS
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon murmur
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping murmur"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon murmur
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
