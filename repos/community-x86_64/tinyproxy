#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=$(pidof -o %PPID /usr/sbin/tinyproxy)

start() {
  stat_busy "Starting Tinyproxy"

  [ -z "$PID" ] && rm -f /var/run/tinyproxy/tinyproxy.pid && \
    /usr/sbin/tinyproxy -c /etc/tinyproxy/tinyproxy.conf 2>/dev/null

  if [ $? -gt 0 ]; then
    stat_fail
  else
    add_daemon tinyproxy
    stat_done
  fi
}

stop() {
  stat_busy "Stopping Tinyproxy"

  [ ! -z "$PID" ]  && kill $PID &> /dev/null

  if [ $? -gt 0 ]; then
    stat_fail
  else
    rm_daemon tinyproxy
    stat_done
  fi
}

case "$1" in
  start)
    start
    ;;
  stop)
    stop
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
