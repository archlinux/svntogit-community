# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bart Verhagen <barrie.verhagen at gmail dot com>

pkgname=catch2
pkgver=2.9.1
pkgrel=1
pkgdesc="Modern, C++-native, header-only, test framework for unit-tests, TDD and BDD"
arch=('any')
url="https://github.com/catchorg/catch2"
license=('Boost')
makedepends=('cmake' 'python') # python seems to be necessary for building tests (FS#60273)
source=("https://github.com/catchorg/Catch2/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('0b36488aca6265e7be14da2c2d0c748b4ddb9c70a1ea4da75736699c629f14ac')

build() {
  cd Catch2-$pkgver

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
  cd Catch2-$pkgver/build
  make test
}

package() {
  cd Catch2-$pkgver/build
  make DESTDIR="$pkgdir" install
}

# vim: ts=2 sw=2 et:
