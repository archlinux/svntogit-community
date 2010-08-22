#!/bin/bash

FC_PATH=/usr/share/java/freecol
LOG_PATH=/tmp/freecol

[ ! -d "$LOG_PATH" ] && install -dm755 $LOG_PATH
cd $LOG_PATH
java -Xmx256M -jar $FC_PATH/FreeCol.jar "$@" --freecol-data $FC_PATH/data \
  &> ./messages.log
