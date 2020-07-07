# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Carl Flippin <carlf@photocarl.org>

pkgbase=libdbi
pkgname=(libdbi libdbi-docs)
pkgver=0.9.0
pkgrel=5
pkgdesc="Database independant abstraction layer for C"
url="http://libdbi.sourceforge.net/"
license=('LGPL')
arch=('x86_64')
depends=('glibc')
options=(!emptydirs)
source=("https://downloads.sourceforge.net/$pkgbase/$pkgbase-$pkgver.tar.gz")
sha1sums=('6c1ecfb78f43a921d5f914299304bd6c82cb0e23')

build() {
  cd $pkgbase-$pkgver
  ./configure --prefix=/usr
  make
}

package_libdbi() {
  cd $pkgbase-$pkgver
  make DESTDIR="$pkgdir" install
  make -C doc DESTDIR="$pkgdir" uninstall
}

package_libdbi-docs() {
  pkgdesc="Developer documentation for libdbi"
  depends=()

  cd $pkgbase-$pkgver
  make -C doc DESTDIR="$pkgdir" install
}
