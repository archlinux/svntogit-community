#!/bin/bash

FC_PATH=/usr/share/java/freecol
LOG_PATH=$(mktemp -d /tmp/freecol.XXX)

[ ! -d "$LOG_PATH" ] && install -dm755 $LOG_PATH
cd $LOG_PATH
java -Xmx512M -jar $FC_PATH/FreeCol.jar "$@" --freecol-data $FC_PATH/data --no-intro &> ./messages.log
