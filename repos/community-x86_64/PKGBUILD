# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Philippe Cherel <philippe.cherel@mayenne.org>
# vim: ft=sh:

pkgname=libcec
pkgver=2.1.1
pkgrel=1
pkgdesc="Pulse-Eight's libcec for the Pulse-Eight USB-CEC adapter"
arch=('i686' 'x86_64')
url="https://github.com/Pulse-Eight/libcec"
license=('GPL')
depends=('udev' 'lockdev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Pulse-Eight/libcec/tarball/$pkgname-$pkgver")
_srcfolder=Pulse-Eight-libcec-605d913
options=(!libtool)
sha256sums=('085cabf38bbe82c0a1c78fc4a0cc318b3c4f5fadae325b3d648821d2a4bf694d')

build() {
  mv "$_srcfolder" "$pkgname-$pkgver"

  cd "$pkgname-$pkgver"
  export CFLAGS="$CFLAGS -fPIC"
  export CXXFLAGS="$CXXFLAGS -fPIC"
  export LDFLAGS="$LDFLAGS -fPIC"
  autoreconf -vif
  ./configure --prefix=/usr
  make
}

package() {
  cd "$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
}
