# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Elmar Klausmeier <Elmar.Klausmeier@gmail.com>

pkgname=sundials
pkgver=6.0.0
pkgrel=2
pkgdesc='Suite of nonlinear differential/algebraic equation solvers'
arch=(x86_64)
url='https://computation.llnl.gov/casc/sundials/main.html'
license=(BSD)
depends=(openmpi suitesparse)
makedepends=(cmake gcc-fortran python)
source=(https://github.com/LLNL/sundials/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz
        sundials-fix-cmake-targets.patch)
sha256sums=('c7178e54df20a9363ae3e5ac5b3ee9db756a4ddd4b8fff045127e93b73b151f4'
            '949206b3237fb918700c87664da5618de49fe019f342583e560e4ce63ebe3a61')

prepare() {
  patch -d $pkgname-$pkgver -p1 < sundials-fix-cmake-targets.patch # FS#70399
  sed -e '/SHOW_IF SUNDIALS_BUILD_WITH_PROFILING/d' -i $pkgname-$pkgver/cmake/SundialsTPLOptions.cmake # Workaround broken cmake config
}

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_C_FLAGS="${CFLAGS} -fPIC -fcommon" \
    -DCMAKE_C_STANDARD=11 \
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
