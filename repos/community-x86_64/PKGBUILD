# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Marco Maso <demind@gmail.com>
# Contributor: Adrian Benson <adrian_benson@yahoo.co.nz>

pkgname=qrupdate
pkgver=1.1.5
pkgrel=1
pkgdesc='Fortran library for fast updates of QR and Cholesky decompositions'
url='https://sourceforge.net/projects/qrupdate'
makedepends=(gcc-fortran cmake)
depends=(lapack)
arch=(x86_64)
license=(GPL3)
source=(https://github.com/mpimd-csc/qrupdate-ng/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('912426f7cb9436bb3490c3102a64d9a2c3883d700268a26d4d738b7607903757')

build() {
  cmake -B build -S $pkgname-ng-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

check() {
  cmake --build build --target test
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
