# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Elmar Klausmeier <Elmar.Klausmeier@gmail.com>

pkgname=sundials
pkgver=4.0.1
pkgrel=3
pkgdesc="Suite of nonlinear differential/algebraic equation solvers"
arch=(x86_64)
url="https://computation.llnl.gov/casc/sundials/main.html"
license=(BSD)
depends=(openmpi)
makedepends=(cmake gcc-fortran python)
source=("http://computation.llnl.gov/projects/sundials/download/$pkgname-$pkgver.tar.gz")
sha256sums=('29e409c8620e803990edbda1ebf49e03a38c08b9187b90658d86bddae913aed4')

prepare() {
  mkdir -p build
}

build() {
  cd build
  cmake ../$pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DMPI_ENABLE=ON \
    -DPTHREAD_ENABLE=ON	\
    -DOPENMP_ENABLE=ON \
    -DF77_INTERFACE_ENABLE=ON \
    -DEXAMPLES_INSTALL_PATH=/usr/share/sundials/examples
  make
}

package() {
  cd build
  make DESTDIR="$pkgdir" install

  install -Dm644 "$srcdir"/$pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}

