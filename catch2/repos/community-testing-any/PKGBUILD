# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bart Verhagen <barrie.verhagen at gmail dot com>

pkgname=catch2
_gitcommit=5c88067bd339465513af4aec606bd2292f1b594a
pkgver=2.13.6
pkgrel=1
pkgdesc="Modern, C++-native, header-only, test framework for unit-tests, TDD and BDD"
arch=('any')
url="https://github.com/catchorg/catch2"
license=('Boost')
makedepends=('git' 'cmake' 'python') # python seems to be necessary for building tests (FS#60273)
source=(${pkgname}::"git+https://github.com/catchorg/Catch2#commit=${_gitcommit}?signed")
sha512sums=('SKIP')
validpgpkeys=(
  E29C46F3B8A7502860793B7DECC9C20E314B2360 # Martin Hořeňovský
  81E70B717FFB27AFDB45F52090BBFF120F9C087B # Jozef Grajciar
)

pkgver() {
  cd ${pkgname}
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

build() {
  cd ${pkgname}
  export CFLAGS+=" ${CPPFLAGS}"
  export CXXFLAGS+=" ${CPPFLAGS}"
  cmake -B build \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DCATCH_USE_VALGRIND=OFF \
    -DCATCH_BUILD_EXAMPLES=OFF \
    -DCATCH_ENABLE_COVERAGE=OFF \
    -DCATCH_ENABLE_WERROR=OFF \
    -DBUILD_TESTING=ON
  make -C build
}

check() {
  cd ${pkgname}
  make -C build test
}

package() {
  cd ${pkgname}
  make -C build DESTDIR="$pkgdir" install
}

# vim: ts=2 sw=2 et:
