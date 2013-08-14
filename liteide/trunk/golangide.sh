#!/bin/sh
ELF=/usr/bin/liteide
if [ ! -z $GOROOT -a -e $GOROOT ]; then
  $ELF $@
else
  GOROOT=/usr/lib/go $ELF $@
fi
