# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Rémy Oudompheng <oudomphe@clipper.ens.fr>
# Contributor: Alessandro "jakedust" Andrioni <jakedust@gmail.com>

pkgname=flint
pkgver=2.4.4
pkgrel=3
pkgdesc="A C library for doing number theory"
arch=('i686' 'x86_64')
url="http://www.flintlib.org"
license=('GPL')
depends=('mpfr' 'ntl')
source=("http://www.flintlib.org/flint-$pkgver.tar.gz")
md5sums=('b527fe3a49fd02a0367227fe8ec9cbe4')

prepare() {
  cd $pkgname-$pkgver
  sed -i.orig 's,.*NTL/g_lip.h,// &,' interfaces/NTL-interface.cpp
}

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --with-gmp=/usr --with-mpfr=/usr --with-ntl=/usr
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
