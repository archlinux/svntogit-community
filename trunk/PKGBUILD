# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Elmar Klausmeier <Elmar.Klausmeier@gmail.com>

pkgname=sundials
pkgver=6.1.0
pkgrel=2
pkgdesc='Suite of nonlinear differential/algebraic equation solvers'
arch=(x86_64)
url='https://computation.llnl.gov/casc/sundials/main.html'
license=(BSD)
depends=(openmpi suitesparse)
makedepends=(cmake gcc-fortran python)
source=(https://github.com/LLNL/sundials/archive/v$pkgver/$pkgname-$pkgver.tar.gz
        sundials-fix-cmake-config.patch)
sha256sums=('286ac6b3567a8b5c8d372391f9061024dc3c6415556c3eb0423be8bdf2de1e77'
            'd7a89b080fd0e71eed54e7dcf0f88ba51245aae200ecf685f4c543d47e2e1983')

prepare() {
  patch -d $pkgname-$pkgver -p1 < sundials-fix-cmake-config.patch # Fix cmake config
}

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
