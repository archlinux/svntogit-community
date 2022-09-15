#!/bin/bash

FC_PATH=/usr/share/java/freecol

java -Xmx2G -jar $FC_PATH/FreeCol.jar "$@" --freecol-data $FC_PATH/data --no-intro
