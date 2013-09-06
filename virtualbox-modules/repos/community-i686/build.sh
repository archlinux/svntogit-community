#!/bin/bash -e
# lazyness can be enhanced everyday

usage() {
  echo "usage: $0 extra"
  echo "       $0 testing"
  exit 1
}

# $1: reference package
update() {
  # expac is required
  type -p expac >/dev/null

  curkernel=$(expac -S '%v' "$1"|sed -r 's/([0-9]+)\.([0-9]+).*/\1.\2/')
  nextkernel=${curkernel%.*}.$(( ${curkernel#*.}+1))

  sed -ri \
    -e "s/(_?extramodules=).*/\1extramodules-$curkernel-ARCH/i" \
    -e "s/(linux.*>=)[0-9]+.[0-9]+/\1$curkernel/" \
    -e "s/(linux.*<)[0-9]+.[0-9]+/\1$nextkernel/" \
    PKGBUILD *.install
}

# $1: repo
build() {
  _pwd=$PWD
  cd /var/empty
  makechrootpkg -cu -I "$_pwd"/../../virtualbox/trunk/virtualbox-host-dkms-*-i686.pkg.tar.xz -r "$1"
  makechrootpkg -I "$_pwd"/../../virtualbox/trunk/virtualbox-guest-dkms-*-i686.pkg.tar.xz  -r "$1"
  cd "$_pwd"
  makechrootpkg -n -r "$1"
}

(( $# == 1 )) || usage

case $1 in
  extra)
    update core/linux-headers
    for arch in i686 x86_64; do
      build /var/lib/archbuild/extra-$arch
    done
  ;;
  testing)
    update testing/linux-headers
    for arch in i686 x86_64; do
      build /var/lib/archbuild/testing-$arch
    done
  ;;
  *)
    usage
  ;;
esac

# vim:set ts=2 sw=2 ft=sh et:
