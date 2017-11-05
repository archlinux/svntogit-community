#!/bin/sh
shortlang=`echo $LANG | cut -b1-2`
if [ ! -d "/usr/share/netsurf/$shortlang" ]; then
  # Use /usr/share/netsurf/en
  export LANG=en_US.UTF-8
fi
/usr/bin/netsurf-gtk3 "$@"
