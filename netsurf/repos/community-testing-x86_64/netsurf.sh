#!/bin/bash
# Use English if a directory for the current language does not exist
test -d "/usr/share/netsurf/${LANG:0:2}" || export LANG=en_US.UTF-8
/usr/bin/netsurf-gtk3 "$@"
