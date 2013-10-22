# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=libnfs
pkgver=1.7.0
pkgrel=2
pkgdesc="client library for accessing NFS shares"
arch=('i686' 'x86_64')
url="https://github.com/sahlberg/libnfs"
license=('GPL')
depends=('glibc')
source=("https://github.com/sahlberg/$pkgname/archive/$pkgname-$pkgver.tar.gz")
sha256sums=('724e0b15cb2099ab3bbdb8456eaab54bc6d1de76da4b4f3251323471523e2114')

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
