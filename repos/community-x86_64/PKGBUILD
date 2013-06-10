# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.6.0
pkgrel=1
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=("https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz")
sha256sums=('19a497044f086d2bed973d0e89392bd41d1a8e9f524d5787f3090f966e20ccc3')
options=(!libtool)

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
