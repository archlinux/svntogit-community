# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.8.0
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=("https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz")
sha256sums=('e4d766efba85e79b04c18038070506d0a9df5b7e0f08aa54ab402892cd1542cc')

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
