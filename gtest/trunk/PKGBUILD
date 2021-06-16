# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Jan Alexander Steffens (heftig) <jan.steffens@gmail.com>
# Contributor: Alexandre Bique <bique.alexandre@gmail.com>
# Contributor: Louis R. Marascio <lrm@fitnr.com>
# Contributor: Cody Maloney <cmaloney@theoreticalchaos.com>
# Contributor: acxz <akashpatel2008 at yahoo dot com>

pkgname=gtest
pkgver=1.11.0
pkgrel=1
pkgdesc='Google Test - C++ testing utility'
url='https://github.com/google/googletest'
arch=('x86_64')
license=('BSD')
depends=('gcc-libs' 'sh')
makedepends=('python' 'cmake' 'gcc-libs' 'sh')
optdepends=('python: gmock generator')
conflicts=('gmock')
replaces=('gmock')
provides=('gmock')
_srcname=googletest-release-${pkgver}
source=(${_srcname}.tar.gz::https://github.com/google/googletest/archive/release-${pkgver}.tar.gz
        gtest-version.patch)
sha512sums=('6fcc7827e4c4d95e3ae643dd65e6c4fc0e3d04e1778b84f6e06e390410fe3d18026c131d828d949d2f20dde6327d30ecee24dcd3ef919e21c91e010d149f3a28'
            'e3e6476d938f65e74a0aa5bbfe58136db937205c8a0536399f46d0096ee728566247b85c82e0067300e465fcbc455a9e0d99611410dece70180aa92170357fbf')

prepare() {
  cd ${_srcname}
  cp ../gtest-version.patch gtest-version.patch
  sed "s|__GOOGLETEST_VERSION__|${pkgver}|g" -i gtest-version.patch
  patch -Np1 -i gtest-version.patch
}

build() {
  cmake -H${_srcname} -Bbuild \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DBUILD_SHARED_LIBS=ON \
    -Dgtest_build_tests=ON
  cmake --build build
}

check() {
  cmake --build build --target test
}

package() {
  DESTDIR="${pkgdir}" cmake --build build --target install

  # Shouldn't be present
  find "${pkgdir}" -name '*.pump' -printf 'Removing %P\n' -delete

  cd ${_srcname}
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CONTRIBUTORS -t "${pkgdir}/usr/share/doc/${pkgname}"

  cd googletest
  install -Dm 755 scripts/gtest-config.in -t "${pkgdir}/usr/bin"
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/googletest/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/googletest/src"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/googletest"

  cd ../googlemock
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/gmock/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/gmock/src"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/gmock"
  install -Dm 644 scripts/generator/{*.py,LICENSE,README*} -t "${pkgdir}/usr/share/gmock/generator"
  install -Dm 644 scripts/generator/cpp/* -t "${pkgdir}/usr/share/gmock/generator/cpp"

  sed -i 's|src/||' "${pkgdir}/usr/src/gmock/src/gmock-all.cc"

  python -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
  python -O -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
}

# vim: ts=2 sw=2 et:
