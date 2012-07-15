#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=$(pidof -o %PPID /usr/bin/wesnothd)

case "$1" in
  start)
    stat_busy "Starting Wesnoth Server Daemon"
    [[ -d /var/run/wesnothd ]] || mkdir /var/run/wesnothd
    [ -z "$PID" ] && /usr/bin/wesnothd -d &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      PID=$(pidof -o %PPID /usr/bin/wesnothd)
      echo $PID > /var/run/wesnotd/pid
      add_daemon wesnothd
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Wesnoth Server Daemon"
    [ ! -z "$PID" ] && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon wesnothd
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
