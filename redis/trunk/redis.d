#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`cat /var/run/redis.pid 2>/dev/null`
case "$1" in
  start)
    stat_busy "Starting Redis Server"
    [ -d /var/lib/redis ] || { mkdir /var/lib/redis; }
    if [ -z "$PID" ]; then
        /usr/bin/redis-server /etc/redis.conf >/dev/null
        RESULT=$?
    else
        REDIS_PID=`pidof redis-server`
        if [ -z "$REDIS_PID" ]; then
            /usr/bin/redis-server /etc/redis.conf >/dev/null
            RESULT=$?
        elif [ `pidof redis-server` -eq $PID ]; then
            RESULT=1
        else
            /usr/bin/redis-server /etc/redis.conf >/dev/null
            RESULT=$?
        fi
    fi

    if [ $RESULT -gt 0 ]; then
      stat_fail
    else
      add_daemon redis
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Redis Server"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm /var/run/redis.pid
      rm_daemon redis
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
