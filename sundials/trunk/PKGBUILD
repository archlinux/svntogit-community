# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Elmar Klausmeier <Elmar.Klausmeier@gmail.com>

pkgname=sundials
pkgver=6.5.0
pkgrel=1
pkgdesc='Suite of nonlinear differential/algebraic equation solvers'
arch=(x86_64)
url='https://computation.llnl.gov/casc/sundials/main.html'
license=(BSD)
depends=(openmpi suitesparse)
makedepends=(cmake gcc-fortran python)
source=(https://github.com/LLNL/sundials/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('7557cdb8fe2a9b56fa0c259aa4e2c2dc488a1c79d482bb7943e27b7d76f6931b')

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DBUILD_STATIC_LIBS=OFF \
    -DENABLE_MPI=ON \
    -DENABLE_PTHREAD=ON	\
    -DENABLE_OPENMP=ON \
    -DENABLE_KLU=ON \
    -DKLU_LIBRARY_DIR=/usr/lib \
    -DEXAMPLES_INSTALL_PATH=/usr/share/sundials/examples
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
