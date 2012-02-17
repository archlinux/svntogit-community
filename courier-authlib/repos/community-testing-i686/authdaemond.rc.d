#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

start() {
  [ -d /var/run/authdaemon ] || mkdir -p /var/run/authdaemon
  chown courier:courier /var/run/authdaemon

  stat_busy "Starting Authdaemond"
  /usr/sbin/authdaemond start &> /dev/null
  if [ $? -gt 0 ]; then
    stat_fail
  else
    add_daemon authdaemond
    stat_done
  fi
}

stop() {
  stat_busy "Stopping Authdaemond"
  /usr/sbin/authdaemond stop &> /dev/null
  if [ $? -gt 0 ]; then
    stat_fail
  else
    rm -f /var/run/authdaemon/{pid.lock,pid,socket} &> /dev/null

    # TODO: Take these out at some point, they're only cleanup for old way
    rm -f /var/run/authdaemond.pid &> /dev/null
    rm -f /var/spool/authdaemon/{pid.lock,pid,socket} &> /dev/null

    rm_daemon authdaemond
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
    # calling 'stop' and 'start' without the $0 fails...
    $0 stop
    sleep 2
    $0 start
    ;;
  *)
    echo "usage: $0 {start|stop|restart}"
esac
exit 0
