#!/bin/bash

FC_PATH=/usr/share/java/freecol

cd $(mktemp -d)
java -Xmx512M -jar $FC_PATH/FreeCol.jar "$@" --freecol-data $FC_PATH/data --no-intro &> ./messages.log
