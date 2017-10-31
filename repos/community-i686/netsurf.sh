#!/bin/sh
shortname=`echo $LANG | cut -b1-2`
if [ ! -d "/usr/share/netsurf/$shortname" ]; then
  export LANG=en
fi
/usr/bin/netsurf-gtk3 "$@"
