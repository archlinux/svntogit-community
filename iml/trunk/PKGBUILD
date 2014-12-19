# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Rémy Oudompheng <oudomphe@clipper.ens.fr>

pkgname=iml
pkgver=1.0.4
pkgrel=2
pkgdesc="C Library of integer matrix algorithms"
arch=('i686' 'x86_64')
url="https://cs.uwaterloo.ca/~astorjoh/iml.html"
license=('GPL')
depends=('gmp' 'cblas')
source=("http://www.cs.uwaterloo.ca/~astorjoh/$pkgname-$pkgver.tar.bz2")
md5sums=('b5958c8d6ba89fff96ee82af6854cf7d')

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --enable-shared --with-cblas=-lcblas
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
