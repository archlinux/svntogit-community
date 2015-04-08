# $Id$
# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=modular_decomposition
pkgver=20100607
pkgrel=1
pkgdesc="An implementation of a modular decomposition algorithm"
arch=(i686 x86_64)
url="http://www.liafa.jussieu.fr/~fm/algos/index.html"
license=(GPL2)
depends=(glibc)
source=("http://www.sagemath.org/packages/upstream/$pkgname/$pkgname-$pkgver.tar.bz2")
md5sums=('9bc5245c5fab9df4f45c8e10c27cf3b8')

build() {
  cd $pkgname-$pkgver
  gcc -o libmodulardecomposition.so dm.c random.c -fPIC --shared
}

package() {
  cd $pkgname-$pkgver
  mkdir -p "$pkgdir"/usr/{include,lib}
  cp libmodulardecomposition.so "$pkgdir"/usr/lib
  cp dm_english.h "$pkgdir"/usr/include/modular_decomposition.h
}
