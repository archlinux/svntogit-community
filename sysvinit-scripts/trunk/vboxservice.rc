#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/${0##*/}

name=VBoxService
PID=$(pidof -o %PPID $name)

case "$1" in
  start)
    stat_busy 'Starting VirtualBox Guest Service'
    [[ -z "$PID" ]] && ${name} $VBOX_SERVICE_OPTION &>/dev/null \
    && { add_daemon ${0##*/}; stat_done; } \
    || { stat_fail; exit 1; }
    ;;
  stop)
    stat_busy 'Stopping VirtualBox Guest Service'
    [[ -n "$PID" ]] && kill $PID &>/dev/null \
    && { rm_daemon ${0##*/}; stat_done; } \
    || { stat_fail; exit 1; }
    ;;
  restart)
    $0 stop
    sleep 1
    $0 start
    ;;
  status)
    stat_busy 'Checking VirtualBox Guest Service status'
    ck_status ${0##*/}
    ;;
  *)
    echo "usage: ${0##*/} {start|stop|restart|status}" >&2
    exit 1
esac

exit 0

# vim:set ts=2 sw=2 ft=sh et:
