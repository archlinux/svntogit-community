#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/inputattach

case "$1" in
  start)
    stat_busy "Starting inputattach"
    for param in "${IAPARAMS[@]}"; do
      if ! /usr/sbin/inputattach --daemon $param; then
        stat_fail
        exit 1
      fi
    done

    add_daemon inputattach
    stat_done
    ;;
  stop)
    stat_busy "Stopping inputattach"
    PID=`pidof -o %PPID /usr/sbin/inputattach`
    [ ! -z "$PID" ] && kill $PID &>/dev/null
    if [ $? -gt 0 ]; then
      stat_fail
      exit 1
    else
      rm_daemon inputattach
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
