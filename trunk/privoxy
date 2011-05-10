#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

# source application-specific settings
[ -f /etc/conf.d/privoxy ] && . /etc/conf.d/privoxy

# read logdir and logfile from privoxy config
prld=`grep ^logdir "$PRIVOXY_CONF" 2>/dev/null | cut -d' ' -f2`
[ -n "$prld" ] || prld=/var/log/privoxy
prlf=`grep ^logfile "$PRIVOXY_CONF" 2>/dev/null | cut -d' ' -f2`
[ -n "$prlf" ] || prlf=logfile

PID=`pidof -o %PPID /usr/sbin/privoxy`

case "$1" in
  start)
    stat_busy "Starting Privoxy"
    # create missing logdir and logfile
    [ -d "$prld" ] || mkdir -p "$prld"
    if [ ! -f "$prlf" ]; then
      touch "$prld/$prlf" && chgrp "${PRIVOXY_GROUP}" "$prld/$prlf" && \
        chmod 0660 "$prld/$prlf"
    fi
    [ -z "$PID" ] && /usr/sbin/privoxy --user ${PRIVOXY_USER}.${PRIVOXY_GROUP} \
                                       ${PRIVOXY_ARGS} ${PRIVOXY_CONF}
    if [ $? -gt 0 ]; then
      stat_fail
    else
      add_daemon privoxy
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping Privoxy"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon privoxy
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
