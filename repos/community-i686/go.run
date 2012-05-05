#!/bin/sh
if [[ -z $GOROOT ]]; then
    export GOROOT=/usr/lib/go
fi
if [[ -z $GOROOT_FINAL ]]; then
    export GOROOT_FINAL=$GOROOT
fi
/usr/bin/go.elf "$@"
