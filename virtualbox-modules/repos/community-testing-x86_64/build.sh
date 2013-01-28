#!/bin/bash

if (( $# != 1 )); then
  echo "usage: $0 extra"
  echo "       $0 testing"
  exit 1
fi

linux32 makechrootpkg -cuI ../../virtualbox/trunk/virtualbox-host-dkms-*-i686.pkg.tar.xz -r /var/lib/archbuild/$1-i686
linux32 makechrootpkg -I ../../virtualbox/trunk/virtualbox-guest-dkms-*-i686.pkg.tar.xz  -r /var/lib/archbuild/$1-i686
linux32 makechrootpkg -r /var/lib/archbuild/$1-i686

makechrootpkg -cuI ../../virtualbox/trunk/virtualbox-host-dkms-*-x86_64.pkg.tar.xz -r /var/lib/archbuild/$1-x86_64
makechrootpkg -I ../../virtualbox/trunk/virtualbox-guest-dkms-*-x86_64.pkg.tar.xz  -r /var/lib/archbuild/$1-x86_64
makechrootpkg -r /var/lib/archbuild/$1-x86_64


# vim:set ts=2 sw=2 ft=sh et:
