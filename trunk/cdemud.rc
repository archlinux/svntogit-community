#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions
. /etc/conf.d/cdemud

case "$1" in
  start)
    stat_busy "Loading vhba and loop modules"
    modprobe vhba
    if [ $? -ne 0 ]; then
      stat_fail
    else
      stat_done
    fi

    stat_busy "Waiting for $CTL_DEVICE"
    i=0
    until [ -c $CTL_DEVICE -o $i -ge 10 ]; do
      i=`expr $i + 1`
      sleep 1
    done
    if [ -c $CTL_DEVICE ]; then
      stat_done
    else
      stat_fail
    fi

    stat_busy "Starting cdemud"
    cdemud --ctl-device=$CTL_DEVICE --bus=$SYSTEM --num-devices=$NUM_DEVICES --audio-driver=$AUDIO_DRIVER --logfile=$LOG_FILE &
    if [ $? -ne 0 ]; then
      stat_fail
    else
      add_daemon cdemud
      stat_done
    fi
    ;;
  stop)
    stat_busy "Stopping cdemud"
    kill -9 `pidof cdemud` &>/dev/null && sleep 1 && rmmod vhba
    if [ $? -ne 0 ]; then
      stat_fail
    else
      rm_daemon cdemud
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
