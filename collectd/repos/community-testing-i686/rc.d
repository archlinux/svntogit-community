#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

name=collectd
prog="/usr/sbin/collectdmon"

PID=$(pidof -o %PPID $prog)

case "$1" in
start)
	stat_busy "Starting $name daemon"
	[[ -z "$PID" ]] && $prog \
	&& { add_daemon $name; stat_done; } \
	|| { stat_fail; exit 1; }
	;;
stop)
	stat_busy "Stopping $name daemon"
	[[ -n "$PID" ]] && kill $PID &>/dev/null \
	&& { rm_daemon $name; stat_done; } \
	|| { stat_fail; exit 1; }
	;;
restart)
	$0 stop
	sleep 2
	$0 start
	;;
reload)
	stat_busy "Sending SIGHUP to $name daemon"
	[[ -n "$PID" ]] && kill -HUP $PID &>/dev/null \
	&& { stat_done; } \
	|| { stat_fail; exit 1; }
	;;
*)
	echo "usage: $0 {start|stop|restart|reload}"
	exit 1
	;;
esac
