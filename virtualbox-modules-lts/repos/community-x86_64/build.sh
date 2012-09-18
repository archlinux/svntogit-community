#!/bin/bash

if (( $# != 2 )); then
  echo "usage: $0 extra multilib"
  echo "       $0 testing multilib-testing"
  exit 1
fi

$1-i686-build
linux32 makechrootpkg -I ../../virtualbox/trunk/virtualbox-host-source-*-i686.pkg.tar.xz -r /var/lib/archbuild/$1-i686
linux32 makechrootpkg -I ../../virtualbox/trunk/virtualbox-guest-source-*-i686.pkg.tar.xz  -r /var/lib/archbuild/$1-i686
linux32 makechrootpkg -r /var/lib/archbuild/$1-i686

$2-build
makechrootpkg -I ../../virtualbox/trunk/virtualbox-host-source-*-x86_64.pkg.tar.xz -r /var/lib/archbuild/$2-x86_64
makechrootpkg -I ../../virtualbox/trunk/virtualbox-guest-source-*-x86_64.pkg.tar.xz  -r /var/lib/archbuild/$2-x86_64
makechrootpkg -r /var/lib/archbuild/$2-x86_64


# vim:set ts=2 sw=2 ft=sh et:
