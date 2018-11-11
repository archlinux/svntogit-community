#!/bin/sh
export LOGOLIB=/usr/lib/logo/logolib
if [[ -f "$1" ]]; then
  /usr/bin/logo.elf "$*" < "$1" | head -n-2
else
  /usr/bin/logo.elf "$@"
fi
