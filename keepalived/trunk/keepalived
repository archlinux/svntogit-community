#!/bin/sh
#
# Startup script for the Keepalived daemon
#
# processname: keepalived
# pidfile: /var/run/keepalived.pid
# config: /etc/keepalived/keepalived.conf
# chkconfig: 35 21 79
# description: Start and stop Keepalived

# Global definitions
PID_FILE="/var/run/keepalived.pid"
. /etc/rc.d/functions
test -f /etc/conf.d/keepalived && . /etc/conf.d/keepalived
# See how we were called.
case "$1" in
  start)
	stat_busy "Starting Keepalived for LVS: "
	keepalived $KEEPALIVED_OPTIONS
	add_daemon keepalived
	stat_done
	;;
  stop)
	echo -n "Shutting down Keepalived for LVS: "
	PID=`cat $PID_FILE`
	kill $PID
	rm -f PID_FILE
	rm_daemon keepalived
	stat_done
	;;
  restart)
	stat_busy "Shutting down Keepalived for LVS: "
	PID=`cat $PID_FILE`
	kill $PID
	echo
	stat_busy "Starting Keepalived for LVS: "
	keepalived $KEEPALIVED_OPTIONS
	stat_done
	;;
  reload)
	stat_busy "Reloading Keepalived config: "
	killall -HUP keepalived
	stat_done
	;;
  *)
	echo "Usage: $0 {start|stop|restart|reload}"
	exit 1
esac

exit 0
