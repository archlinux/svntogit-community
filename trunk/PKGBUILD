# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Elmar Klausmeier <Elmar.Klausmeier@gmail.com>

pkgname=sundials
pkgver=5.7.0
pkgrel=2
pkgdesc="Suite of nonlinear differential/algebraic equation solvers"
arch=(x86_64)
url="https://computation.llnl.gov/casc/sundials/main.html"
license=(BSD)
depends=(openmpi suitesparse)
makedepends=(cmake gcc-fortran python)
source=(https://computation.llnl.gov/projects/sundials/download/$pkgname-$pkgver.tar.gz
        sundials-fix-cmake-targets.patch)
sha256sums=('8d6dd094feccbb8d6ecc41340ec16a65fabac82ed4415023f6d7c1c2390ea2f3'
            '949206b3237fb918700c87664da5618de49fe019f342583e560e4ce63ebe3a61')

prepare() {
  patch -d $pkgname-$pkgver -p1 < sundials-fix-cmake-targets.patch # FS#70399
}

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_C_FLAGS="${CFLAGS} -fPIC -fcommon" \
    -DENABLE_MPI=ON \
    -DENABLE_PTHREAD=ON	\
    -DENABLE_OPENMP=ON \
    -DBUILD_FORTRAN77_INTERFACE=ON \
    -DENABLE_KLU=ON \
    -DKLU_LIBRARY_DIR=/usr/lib \
    -DEXAMPLES_INSTALL_PATH=/usr/share/sundials/examples
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
