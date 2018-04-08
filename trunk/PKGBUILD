# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Bart Verhagen <barrie.verhagen at gmail dot com>
pkgname='catch2'
pkgver=2.2.2
pkgrel=1
pkgdesc="A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD - using C++11, C++14, C++17 and later"
arch=('any')
url="https://github.com/catchorg/catch2"
license=('Boost')
makedepends=("cmake")
source=("https://github.com/catchorg/Catch2/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('e93aacf012579093fe6b4e686ff0488975cabee1e6b4e4f27a0acd898e8f09fd')

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
  cd "$srcdir/Catch2-$pkgver"
  build/SelfTest
}

package() {
  cd "$srcdir/Catch2-$pkgver/build"
  make DESTDIR="$pkgdir" install
}
