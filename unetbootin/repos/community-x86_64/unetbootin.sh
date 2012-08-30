#!/bin/sh
# wrapper script for starting unetbootin with root permissions
ELF=/usr/bin/unetbootin.elf
if [ -e /usr/bin/pkexec ]; then
  pkexec $ELF && exit 0
fi
if [ -z "$KDE_FULL_SESSION" ]; then
  if [ -e /usr/bin/gksudo ]; then
      gksudo $ELF && exit 0
  fi
  if [ -e /usr/bin/gksu ]; then
      gksu $ELF && exit 0
  fi
  echo "Could not use pkexec, gksudo or gksu"
  $ELF && exit 0 || exit 1
fi  
if [ -e /usr/bin/kdesudo ]; then
  kdesudo $ELF && exit 0
fi
if [ -e /usr/bin/kdesu ]; then
  kdesu $ELF && exit 0
fi
echo "Could not use kdesudo or kdesu"
$ELF && exit 0 || exit 1
