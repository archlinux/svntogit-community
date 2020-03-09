# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Giuseppe Borzi <gborzi _AT_ ieee _DOT_ org>

pkgname=openblas
_pkgname=OpenBLAS
pkgver=0.3.9
pkgrel=1
pkgdesc="An optimized BLAS library based on GotoBLAS2 1.13 BSD"
arch=('x86_64')
url="https://www.openblas.net/"
license=('BSD')
depends=('gcc-libs')
makedepends=('perl' 'gcc-fortran')
provides=('blas=3.8.0')
conflicts=('blas')
source=(${_pkgname}-v${pkgver}.tar.gz::https://github.com/xianyi/OpenBLAS/archive/v${pkgver}.tar.gz)
sha512sums=('e34da25b3aaf959ec12826ac68c81e739e453d44f2dba28b15e57d7a827edc4d5f42988e9b6d98ac07999940be7b5876246cb3a980e590ae87f77f4c2f12f40a')

build() {
  cd "$srcdir/$_pkgname-$pkgver"

  make NO_STATIC=1 NO_LAPACK=1 NO_LAPACKE=1 NO_CBLAS=1 NO_AFFINITY=1 USE_OPENMP=1 \
       CFLAGS="$CPPFLAGS $CFLAGS" DYNAMIC_ARCH=1 \
       NUM_THREADS=64 MAJOR_VERSION=3 libs shared
}

package() {
  cd "$srcdir/$_pkgname-$pkgver"

  make PREFIX="$pkgdir"/usr NUM_THREADS=64 MAJOR_VERSION=3 install
  rm -f "$pkgdir"/usr/include/cblas.h "$pkgdir"/usr/include/lapack*
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  cd "$pkgdir"/usr/lib/
  ln -s libopenblasp-r$pkgver.so libblas.so
  ln -s libopenblasp-r$pkgver.so libblas.so.3
  sed -i -e "s%$pkgdir%%" "$pkgdir"/usr/lib/cmake/openblas/OpenBLASConfig.cmake
  sed -i -e "s%$pkgdir%%" "$pkgdir"/usr/lib/pkgconfig/openblas.pc
  ln -s openblas.pc "$pkgdir"/usr/lib/pkgconfig/blas.pc

  rmdir "$pkgdir"/usr/bin
}

# vim:set ts=2 sw=2 et:
