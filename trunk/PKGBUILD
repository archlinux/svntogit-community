# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>
# Contributor: Joaquim Pedro (osmano807) <osmano807@gmail.com>

pkgname=kyotocabinet
pkgver=1.2.79
pkgrel=1
pkgdesc="a modern implementation of DBM in C++"
arch=('x86_64')
url="https://fallabs.com/kyotocabinet"
license=('LGPL3')
depends=('zlib' 'gcc-libs')
source=("https://fallabs.com/${pkgname}/pkg/${pkgname}-${pkgver}.tar.gz")
sha512sums=('9243192c81d3aa37cc8c80eb3bdf235192a0919b134cededa2b4178be515d148916e7405e094cbcdd7dbf13bf38a569bf21863afac7cc05d6418cca5853a2ff4')

build() {
  cd $pkgname-$pkgver

  ./configure --prefix=/usr --disable-opt
  make
}

package() {
  cd $pkgname-$pkgver

  make install DESTDIR="$pkgdir/"
}
