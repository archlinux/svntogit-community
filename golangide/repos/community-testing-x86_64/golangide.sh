#!/bin/sh
ELF=/usr/bin/liteide
# The libqjson issue has been reported upstream
if [ ! -z $GOROOT -a -e $GOROOT ]; then
  LD_PRELOAD=/usr/lib/libqjson.so $ELF $@
else
  GOROOT=/usr/lib/go LD_PRELOAD=/usr/lib/libqjson.so $ELF $@
fi
