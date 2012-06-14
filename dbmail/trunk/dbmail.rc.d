#!/bin/bash

[ -f /etc/conf.d/dbmail ] && . /etc/conf.d/dbmail

. /etc/rc.conf
. /etc/rc.d/functions

case "$1" in
    start)
	mkdir -p /var/run/dbmail
	chown -R nobody:nobody /var/run/dbmail
	for daemon in $DBMAIL_DAEMONS; do
	    stat_busy "Starting DbMail ${daemon}"
	    /usr/sbin/${daemon} -p /var/run/dbmail/${daemon}.pid
	    if [ $? -gt 0 ]; then
		stat_fail
	    else
		stat_done
	    fi
	done
	add_daemon dbmail
	;;
    stop)
	for daemon in $DBMAIL_DAEMONS; do
	    stat_busy "Stopping DbMail ${daemon}"
	    pid=$(cat /var/run/dbmail/${daemon}.pid 2>/dev/null)
	    kill $pid 2>/dev/null
	    while kill -0 "$pid" 2>/dev/null; do
	        sleep 0.2
	    done
	    stat_done
	done
	rm_daemon dbmail
	;;
    restart)
	$0 stop
	sleep 3
	$0 start
	;;
    *)
	echo "usage: $0 {start|stop|restart}"
	;;
esac

exit 0
