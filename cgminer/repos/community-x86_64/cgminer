#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

DAEMON=cgminer

# stupid patch var
export HOME=/root

[ -r /etc/conf.d/$DAEMON ] && . /etc/conf.d/$DAEMON

if [ -r $CGMINER_CONF ]; then
  ARGS="--config $CGMINER_CONF $CGMINER_ARGS"
else
  ARGS="--url $CGMINER_PROTOCOL://$CGMINER_IP:$CGMINER_PORT --user $CGMINER_USER --pass $CGMINER_PASS $CGMINER_ARGS"
fi

PID=$(get_pid $DAEMON)

case "$1" in
  start)
    stat_busy "Starting $DAEMON"
    [ -z "$PID" ] && $DAEMON $ARGS &>/dev/null &
    if [ $? = 0 ]; then
      add_daemon $DAEMON
      stat_done
    else
      stat_fail
      exit 1
    fi
    ;;
  stop)
    stat_busy "Stopping $DAEMON"
    [ -n "$PID" ] && kill $PID &>/dev/null
    if [ $? = 0 ]; then
      rm_daemon $DAEMON
      stat_done
    else
      stat_fail
      exit 1
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
