#!/bin/bash

# Credits to:
# Sebastien Luttringer <seblu+arch@seblu.net>
# Bart De Schuymer <bdschuym@pandora.be>
# Rok Papez <rok.papez@arnes.si>
# Dag Wieers <dag@wieers.com>

. /etc/rc.conf
. /etc/rc.d/functions

#default configuration:
EBTABLES_TEXT_FORMAT="yes"
EBTABLES_BINARY_FORMAT="yes"
EBTABLES_MODULES_UNLOAD="yes"
EBTABLES_SAVE_ON_STOP="no"
EBTABLES_SAVE_ON_RESTART="no"
EBTABLES_SAVE_COUNTER="no"

[[ -r "/etc/conf.d/ebtables" ]] && . "/etc/conf.d/ebtables"

RETVAL=0

start() {
	stat_busy "Starting ebtables"
	! ck_daemon ebtables && stat_done && RETVAL=0 && return
	if [[ "$EBTABLES_BINARY_FORMAT" = yes ]]; then
		for table in $(ls /etc/ebtables/ebtables.* 2>/dev/null | sed -e 's/.*ebtables\.//' -e '/save/d' ); do
			/usr/sbin/ebtables -t ${table} --atomic-file /etc/ebtables/ebtables.${table} --atomic-commit || RETVAL=1
		done
	elif [[ "$EBTABLES_TEXT_FORMAT" = "yes" ]]; then
		[[ ! -r /etc/ebtables/ebtables ]] && :>/etc/ebtables/ebtables
		/usr/sbin/ebtables-restore </etc/ebtables/ebtables || RETVAL=1
	else
		RETVAL=1
	fi

	if (( RETVAL == 0 )); then
		stat_done
		add_daemon ebtables
	else
		stat_fail
	fi
}

stop() {
	stat_busy "Stopping ebtables"
	ck_daemon ebtables && stat_done && RETVAL=0 && return
	for table in $(grep '^ebtable_' /proc/modules | sed -e 's/ebtable_\([^ ]*\).*/\1/'); do
		/usr/sbin/ebtables -t $table --init-table || RETVAL=1
	done

	if [[ "$EBTABLES_MODULES_UNLOAD" = yes ]]; then
		for mod in $(grep -E '^(ebt|ebtable)_' /proc/modules | cut -f1 -d' ') ebtables; do
			/sbin/rmmod $mod 2> /dev/null
		done
	fi

	if (( RETVAL == 0 )); then
		rm_daemon ebtables
		stat_done
	else
		stat_fail
	fi
}

restart() {
	stop
	sleep 1
	start
}

save() {
	stat_busy "Saving ebtables"
	if [[ "$EBTABLES_TEXT_FORMAT" = yes ]]; then
		if [[ -r /etc/ebtables/ebtables ]]; then
			mv -f /etc/ebtables/ebtables /etc/ebtables/ebtables.save
		fi
		/usr/sbin/ebtables-save >/etc/ebtables/ebtables || RETVAL=1
	fi
	if [[ "$EBTABLES_BINARY_FORMAT" = yes ]]; then
		rm -f /etc/ebtables/ebtables.*.save
		for oldtable in $(ls /etc/ebtables/ebtables.* 2>/dev/null | grep -vF 'ebtables.save'); do
			mv -f $oldtable $oldtable.save
		done
		for table in $(grep '^ebtable_' /proc/modules | sed -e 's/ebtable_\([^ ]*\).*/\1/'); do
			:> /etc/ebtables/ebtables.$table
			/usr/sbin/ebtables -t $table --atomic-file /etc/ebtables/ebtables.$table --atomic-save || RETVAL=1
			if [[ "$EBTABLES_SAVE_COUNTER" = no ]]; then
				/usr/sbin/ebtables -t $table --atomic-file /etc/ebtables/ebtables.$table -Z || RETVAL=1
			fi
		done
	fi

	(( RETVAL == 0 )) && stat_done || stat_fail
}

case "$1" in
  start)
		start
	;;
  stop)
		[[ "$EBTABLES_SAVE_ON_STOP" = yes ]] && save
		stop
	;;
  restart|reload)
		[[ "$EBTABLES_SAVE_ON_RESTART" = yes ]] && save
		restart
	;;
  condrestart)
		! ck_daemon ebtables && restart
		RETVAL=$?
	;;
  save)
		save
	;;
  status)
		/usr/sbin/ebtables-save
		RETVAL=$?
	;;
  *)
		echo "Usage $0 {start|stop|restart|condrestart|save|status}"
		RETVAL=1
esac

exit $RETVAL

# vim:set ts=2 sw=2 ft=sh noet:
