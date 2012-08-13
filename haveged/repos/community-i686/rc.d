#!/bin/bash
##
# chkconfig: 2345 75 25
# description: havege entropy daemon
#
# source function library
. /etc/rc.conf
. /etc/rc.d/functions

RETVAL=0
prog="haveged"

case "$1" in
start)
  stat_busy $"Starting $prog"
  /usr/sbin/$prog -w 1024 -v 1
  if [ $? -gt 0 ]; then
    stat_fail
  else
    add_daemon $prog
    stat_done
  fi
  ;;

stop)
  stat_busy $"Stopping $prog"
  kill `cat /var/run/$prog.pid`
  if [ $? -gt 0 ]; then
    stat_fail
  else
    rm_daemon $prog
    stat_done
    rm -f /var/lock/$prog
  fi
  ;;
  
restart)
  $0 stop
  $0 start
  ;;

*)
  echo "usage: $prog [start|stop|restart]"
esac
