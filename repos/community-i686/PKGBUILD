# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=eclib
pkgver=20141106
pkgrel=1
pkgdesc="Includes mwrank (for 2-descent on elliptic curves over Q) and modular symbol code used to create the elliptic curve database"
arch=('i686' 'x86_64')
url="https://github.com/JohnCremona/eclib/"
license=('GPL')
depends=('ntl' 'pari')
source=("https://github.com/JohnCremona/eclib/archive/$pkgname-$pkgver.tar.gz")
md5sums=('dd65b29741461a7abd02c721b9f0c80d')

build() {
  cd eclib-$pkgname-$pkgver
  ./autogen.sh
  ./configure --prefix=/usr
  make
}

package() {
  cd eclib-$pkgname-$pkgver
  make install DESTDIR="$pkgdir"
}

