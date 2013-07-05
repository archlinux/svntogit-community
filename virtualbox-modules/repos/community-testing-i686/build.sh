#!/bin/bash

set -e

if (( $# != 1 )); then
  echo "usage: $0 extra"
  echo "       $0 testing"
  exit 1
fi

here=$PWD
cd /var/empty
linux32 makechrootpkg -cu -I "$here"/../../virtualbox/trunk/virtualbox-host-dkms-*-i686.pkg.tar.xz -r /var/lib/archbuild/$1-i686
linux32 makechrootpkg -I "$here"/../../virtualbox/trunk/virtualbox-guest-dkms-*-i686.pkg.tar.xz  -r /var/lib/archbuild/$1-i686
cd "$here"
linux32 makechrootpkg -n -r /var/lib/archbuild/$1-i686

cd /var/empty
makechrootpkg -cu -I "$here"/../../virtualbox/trunk/virtualbox-host-dkms-*-x86_64.pkg.tar.xz -r /var/lib/archbuild/$1-x86_64
makechrootpkg -I "$here"/../../virtualbox/trunk/virtualbox-guest-dkms-*-x86_64.pkg.tar.xz  -r /var/lib/archbuild/$1-x86_64
cd "$here"
makechrootpkg -n -r /var/lib/archbuild/$1-x86_64


# vim:set ts=2 sw=2 ft=sh et:
