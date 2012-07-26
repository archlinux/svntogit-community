#!/bin/bash

[ -f /etc/conf.d/hdapsd ] && source /etc/conf.d/hdapsd

OPTS="-bp"

if [ -z "${DEVICE}" ]; then
  OPTS="${OPTS} -d sda"
else
  for i in ${DEVICE[@]}; do
    OPTS="${OPTS} -d ${i}"
  done
fi

[ ! -z "${SENSITIVITY}" ] && OPTS="${OPTS} -s ${SENSITIVITY}"
[ "${ADAPTIVE}" == "yes" ] && OPTS="${OPTS} -a"
[ "${SYSLOG}" == "yes" ] && OPTS="${OPTS} -l"
[ "${FORCE}" == "yes" ] && OPTS="${OPTS} -f"

/usr/sbin/hdapsd ${OPTS}
