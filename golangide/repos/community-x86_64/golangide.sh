#!/bin/sh
if [ ! -z $GOROOT -a -e $GOROOT ]; then
  /usr/bin/liteide
else
  GOROOT=/usr/lib/go /usr/bin/liteide
fi
