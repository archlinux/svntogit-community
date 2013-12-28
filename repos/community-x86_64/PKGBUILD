# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Philippe Cherel <philippe.cherel@mayenne.org>
# vim: ft=sh:

pkgname=libcec
pkgver=2.1.4
pkgrel=1
pkgdesc="Pulse-Eight's libcec for the Pulse-Eight USB-CEC adapter"
arch=('i686' 'x86_64')
url="http://libcec.pulse-eight.com/"
license=('GPL')
depends=('udev' 'lockdev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Pulse-Eight/$pkgname/archive/$pkgname-$pkgver.tar.gz")

build() {
  cd "$pkgname-$pkgname-$pkgver"
  autoreconf -vif
  ./configure --prefix=/usr
  make
}

package() {
  cd "$pkgname-$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
}
sha256sums=('79bef5232a5c9ab987ca3a2d4bfcaeb80480fd26f502dc1a996fe845d90fe147')
