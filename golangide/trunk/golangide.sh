#!/bin/sh
if [ ! -z $GOROOT -a -e $GOROOT ]; then
  /usr/bin/liteidex $@
else
  GOROOT=/usr/lib/go /usr/bin/liteidex $@
fi
