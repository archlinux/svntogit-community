#!/bin/bash

[ -f /etc/conf.d/hdapsd ] && . /etc/conf.d/hdapsd

. /etc/rc.conf
. /etc/rc.d/functions

PIDFILE=/var/run/hdapsd.pid
PID=`cat ${PIDFILE} 2> /dev/null`
	
case "$1" in
  start)
    stat_busy "Starting hdapsd"

    ## The daemon will try to autoload the kernel module
    #if [ ! -d /sys/devices/platform/hdaps ]; then
    #    stat_fail
    #    echo "You need to load the hdaps kernel module."
    #    exit 1
    #fi

    ## Set up options to the hdapsd daemon
    HDAPSD_OPTS="-bp"
    if [ -z "${DEVICE}" ]; then
      HDAPSD_OPTS="${HDAPSD_OPTS} -d sda"
    else
      for i in ${DEVICE[@]}; do
        HDAPSD_OPTS="${HDAPSD_OPTS} -d ${i}"
      done
    fi
    [ ! -z "${SENSITIVITY}" ] && HDAPSD_OPTS="${HDAPSD_OPTS} -s ${SENSITIVITY}"
    [ "${ADAPTIVE}" = "yes" ] && HDAPSD_OPTS="${HDAPSD_OPTS} -a"
    [ "${SYSLOG}" = "yes" ]   && HDAPSD_OPTS="${HDAPSD_OPTS} -l"
    [ "${FORCE}" = "yes" ]    && HDAPSD_OPTS="${HDAPSD_OPTS} -f"
    [ -z "${PID}" ] && /usr/sbin/hdapsd ${HDAPSD_OPTS}
    if [ ${?} -gt 0 ]; then
      stat_fail 
    else
      add_daemon hdapsd 
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping hdapsd"
    [ ! -z "${PID}" ] && kill $PID &> /dev/null
    if [ ${?} -gt 0 ]; then
      stat_fail
    else
      rm_daemon hdapsd 
      stat_done
    fi
    ;;
  restart)
    ${0} stop
    sleep 1
    ${0} start
    ;;
  *)
    echo "usage: ${0} {start|stop|restart}"  
esac
