#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/rdnssd

PIDFILE="/var/run/rdnssd.pid"
PID=`cat "$PIDFILE" 2>/dev/null`
case "$1" in
  start)
    stat_busy "Starting RDNSS Daemon"
    if [ ! -z "$PID" -a -e "/proc/$PID" ]; then
      stat_append "-- Already running"
      stat_die
    else
      /usr/sbin/rdnssd -p "$PIDFILE"    \
        ${MERGEHOOK/*/-H}  "$MERGEHOOK" \
        ${RUN_AS/*/-u}     "$RUN_AS"

      if [ $? -gt 0 ]; then
        stat_fail
      else
        add_daemon rdnssd
        stat_done
      fi
    fi
    ;;
  stop)
    stat_busy "Stopping RDNSS Daemon"
    if [ -z "$PID" ]; then
      stat_append "-- Not running"
      stat_die
    else
      kill $PID &> /dev/null
      if [ $? -gt 0 ]; then
        stat_fail
      else
        rm_daemon sshd
        stat_done
      fi
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
