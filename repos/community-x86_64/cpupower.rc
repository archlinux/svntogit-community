#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

[[ -f /etc/conf.d/cpupower ]] && . /etc/conf.d/cpupower

case "$1" in
  start|restart)
    stat_busy "Setting cpupower rules"

    declare params=''
    if [[ "$governor" ]]; then
      params="-g $governor "
      params+="${min_freq:+-d $min_freq} "
      params+="${max_freq:+-u $max_freq} "
      params+="${freq:+-f $freq} "
      cpupower frequency-set $params >/dev/null || { stat_fail; exit 1; }
      stat_done
    else
      stat_append ': Invalid configuration'
      stat_fail 
    fi
  ;;
  *)
  echo "usage: $0 {start|restart}"  
esac

true

# vim:set ts=2 sw=2 ft=sh et:
