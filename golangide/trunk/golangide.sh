#!/bin/sh
# The libqjson issue has been reported upstream
if [ ! -z $GOROOT -a -e $GOROOT ]; then
  LD_PRELOAD=/usr/lib/libqjson.so /usr/bin/liteidex $@
else
  GOROOT=/usr/lib/go LD_PRELOAD=/usr/lib/libqjson.so /usr/bin/liteidex $@
fi
