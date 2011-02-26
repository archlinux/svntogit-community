#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/quassel

PIDFILE=/var/run/quassel.pid
PID=`pidof -o %PPID /usr/bin/quasselcore`

case "$1" in
  start)
    stat_busy "Starting Quassel Core"
    [ -z "$PID" ] && su -l -c "/usr/bin/quasselcore --configdir=/var/lib/quassel --listen=$LISTEN &" $QUASSEL_USER &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      echo $PID > $PIDFILE
      add_daemon quassel
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Quassel Core"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm -f $PIDFILE
      rm_daemon quassel
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
