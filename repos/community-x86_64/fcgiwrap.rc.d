#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

DAEMON=fcgiwrap

# source application-specific settings
[ -f /etc/conf.d/$DAEMON ] && . /etc/conf.d/$DAEMON

# set defaults if settings are missing
[ -z "$SPAWNER" ] && SPAWNER='/usr/bin/spawn-fcgi'
[ -z "$SPAWNER_ARGS" ] && SPAWNER_ARGS='-a 127.0.0.1 -p 9001 -u http -g http -- /usr/sbin/fcgiwrap'

get_pid() {
  pidof -o %PPID $DAEMON
}

case "$1" in
  start)
    stat_busy "Starting $DAEMON daemon"

    PID=$(get_pid)
    if [ -z "$PID" ]; then
      [ -f /var/run/$DAEMON.pid ] && rm -f /var/run/$DAEMON.pid
      # RUN
      $SPAWNER $SPAWNER_ARGS &> /dev/null
      #
      if [ $? -gt 0 ]; then
        stat_fail
        exit 1
      else
        echo $(get_pid) > /var/run/$DAEMON.pid
        add_daemon $DAEMON
        stat_done
      fi
    else
      stat_fail
      exit 1
    fi
    ;;

  stop)
    stat_busy "Stopping $DAEMON daemon"
    PID=$(get_pid)
    # KILL
    [ ! -z "$PID" ] && kill $PID &> /dev/null
    #
    if [ $? -gt 0 ]; then
      stat_fail
      exit 1
    else
      rm -f /var/run/$DAEMON.pid &> /dev/null
      rm_daemon $DAEMON
      stat_done
    fi
    ;;

  restart)
    $0 stop
    sleep 3
    $0 start
    ;;

  status)
    stat_busy "Checking $DAEMON status";
    ck_status $DAEMON
    ;;

  *)
    echo "usage: $0 {start|stop|restart|status}"
esac

exit 0
