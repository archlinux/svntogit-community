#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID /usr/bin/mpdscribble`
case "$1" in
  start)
    stat_busy "Starting mpdscribble"
    [ -z "$PID" ] && /usr/bin/mpdscribble &
    if [ $? -gt 0 ]; then
      stat_fail
    else
      echo $PID > /var/run/mpdscribble.pid
      add_daemon mpdscribble
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping mpdscribble"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm /var/run/mpdscribble.pid
      rm_daemon mpdscribble
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
