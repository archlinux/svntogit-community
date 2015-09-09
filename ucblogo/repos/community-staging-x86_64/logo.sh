#!/bin/sh
export LOGOLIB=/usr/lib/logo/logolib
if [[ -f "$1" ]]; then
  cat "$1" | /usr/bin/logo.elf "$*" | head -n-2
else
  /usr/bin/logo.elf "$@"
fi
