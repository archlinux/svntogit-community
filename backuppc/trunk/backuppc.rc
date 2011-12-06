#!/bin/bash

. /etc/rc.conf
. /etc/rc.d/functions

PID=`pidof -o %PPID -x /opt/BackupPC/bin/BackupPC`
case "$1" in
  start)
    stat_busy "Starting BackupPC Daemon"
    if [ -z "$PID" ]; then 
       su backuppc -c "/opt/BackupPC/bin/BackupPC -d"
       
    if [ $? -gt 0 ]; then
       stat_fail
    else
       add_daemon BackupPC
       stat_done
    fi
    else
       echo -n "Already running!"
       stat_fail
    fi
    ;;       
  stop)
    stat_busy "Stopping BackupPC Daemon"
    [ ! -z "$PID" ]  && kill $PID &> /dev/null
    if [ $? -gt 0 ]; then
      stat_fail
    else
      rm_daemon BackupPC
      stat_done
    fi
    ;;
  restart)
    $0 stop
    sleep 3
    $0 start
    ;;
  *)
    echo "usage: $0 {start|stop|restart}"  
esac
exit 0