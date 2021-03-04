# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=darts
pkgver=0.32
pkgrel=1
pkgdesc="C++ Template Library for implementation of Double-Array"
arch=('x86_64')
url="http://chasen.org/~taku/software/darts/"
license=('BSD' 'LGPL')
depends=('gcc-libs')
source=("http://chasen.org/~taku/software/darts/src/darts-$pkgver.tar.gz")
sha256sums=('0dfc0b82f0a05d93b92acf849368e54bf93f1de8ffb31ba0a21e45ab9e269285')

build() {
  cd darts-$pkgver
  ./configure --prefix=/usr --libexecdir=/usr/lib
  make
}

check() {
  cd darts-$pkgver
  make check
}

package() {
  cd darts-$pkgver
  make DESTDIR="$pkgdir" install

  install -Dm644 COPYING BSD -t "$pkgdir"/usr/share/licenses/$pkgname/
}
