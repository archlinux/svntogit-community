#!/bin/bash

CI_DAEMONS=
[ -f /etc/conf.d/courier-imap ] && . /etc/conf.d/courier-imap
[ -z $AUTO_AUTHDAEMON_LAG ]   && AUTO_AUTHDAEMON_LAG=2
[ -z $AUTO_AUTHDAEMON ]       && AUTO_AUTHDAEMON="false"

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
  start)

    [ -d /var/run/courier ] || mkdir -p /var/run/courier
	chown courier:courier /var/run/courier

    if [ "$AUTO_AUTHDAEMON" == "true" ]; then
      /etc/rc.d/authdaemond start
      sleep ${AUTO_AUTHDAEMON_LAG}
    fi
    if [ ! -f /run/daemons/authdaemond ]; then
      echo "ERROR: authdaemond is not running"
      stat_fail
      exit 1
    fi
    for daemon in $CI_DAEMONS; do
      stat_busy "Starting Courier ${daemon}"
      /usr/lib/courier-imap/${daemon}.rc start
      if [ $? -gt 0 ]; then
        stat_fail
      else
        add_daemon $daemon
        stat_done
      fi
    done
    ;;
  stop)
    for daemon in $CI_DAEMONS; do
      stat_busy "Stopping Courier ${daemon}"
      /usr/lib/courier-imap/$daemon.rc stop > /dev/null
      if [ $? -gt 0 ]; then
        stat_fail
      else
        rm_daemon $daemon
        stat_done
      fi
    done
    if [ "$AUTO_AUTHDAEMON" == "true" ]; then
      /etc/rc.d/authdaemond stop
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
~                                                                                                                                                         
~         
