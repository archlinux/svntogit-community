#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

function check_config {
  stat_busy "Checking nginx configuration"
  /usr/sbin/nginx -t -q -c /etc/nginx/nginx.conf
  if [ $? -ne 0 ]; then
    stat_die
  else
    stat_done
  fi
}

case "$1" in
  start)
    check_config
    $0 careless_start
    ;;
  careless_start)
    stat_busy "Starting nginx"
    if [ -s /var/run/nginx.pid ]; then
      stat_fail
      # probably ;)
      stat_busy "Nginx is already running"
      stat_die
     fi
    /usr/sbin/nginx -c /etc/nginx/nginx.conf &>/dev/null
    if [ $? -ne 0 ]; then
      stat_fail
    else
      add_daemon nginx
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping nginx"
    PID=$(cat /var/run/nginx.pid)
    kill -QUIT $PID &>/dev/null
    if [ $? -ne 0 ]; then
      stat_fail
    else
      for i in {1..10}; do
        [ -d /proc/$PID ] || { stat_done; rm_daemon nginx; exit 0; }
        sleep 1
      done
      stat_fail
    fi
    ;;
  restart)
    check_config
    $0 stop
    sleep 1
    $0 careless_start
    ;;
  reload)
    check_config
    if [ -s /var/run/nginx.pid ]; then
      status "Reloading nginx configuration" kill -HUP $(cat /var/run/nginx.pid)
    fi
    ;;
  check)
    check_config
    ;;
  *)
    echo "usage: $0 {start|stop|restart|reload|check|careless_start}"
esac
