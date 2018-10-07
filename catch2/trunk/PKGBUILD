# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Bart Verhagen <barrie.verhagen at gmail dot com>
pkgname='catch2'
pkgver=2.4.1
pkgrel=2
pkgdesc="A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD - using C++11, C++14, C++17 and later"
arch=('any')
url="https://github.com/catchorg/catch2"
license=('Boost')
makedepends=('cmake' 'python') # python seems to be necessary for building tests (FS#60273)
source=("https://github.com/catchorg/Catch2/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('e1b559d77bd857cb0f773e3e826ac1d7e016cf14057fd14b9e99ec3b2c6b809f')

build() {
  cd "$srcdir/Catch2-$pkgver"

  mkdir -p build
  cd build
  cmake .. \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DCATCH_USE_VALGRIND=OFF \
    -DCATCH_BUILD_EXAMPLES=OFF \
    -DCATCH_ENABLE_COVERAGE=OFF \
    -DCATCH_ENABLE_WERROR=OFF \
    -DBUILD_TESTING=ON
  make
}

check() {
  cd "$srcdir/Catch2-$pkgver/build"
  make test
}

package() {
  cd "$srcdir/Catch2-$pkgver/build"
  make DESTDIR="$pkgdir" install
}
