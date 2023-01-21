# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Jan Alexander Steffens (heftig) <jan.steffens@gmail.com>
# Contributor: Alexandre Bique <bique.alexandre@gmail.com>
# Contributor: Louis R. Marascio <lrm@fitnr.com>
# Contributor: Cody Maloney <cmaloney@theoreticalchaos.com>
# Contributor: acxz <akashpatel2008 at yahoo dot com>

pkgname=gtest
pkgver=1.13.0
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
_srcname=googletest-${pkgver}
source=(${_srcname}.tar.gz::https://github.com/google/googletest/archive/v${pkgver}.tar.gz
        gtest-version.patch)
sha512sums=('70c0cfb1b4147bdecb467ecb22ae5b5529eec0abc085763213a796b7cdbd81d1761d12b342060539b936fa54f345d33f060601544874d6213fdde79111fa813e'
            'ebfd53ac33298e870c04a1f89609d8327152d3d73e7842219af3a11d5ee484033543064b557cc9c8f45057e608e0ee347318070a3ea5d17040bace02110ed8df')

prepare() {
  cd ${_srcname}
  sed "s|__GOOGLETEST_VERSION__|${pkgver}|g" -i ../gtest-version.patch
  patch -Np1 -i ../gtest-version.patch
}

build() {
 cmake -H${_srcname} -Bbuild \
    -DCMAKE_INSTALL_PREFIX=/usr \
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
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/googletest/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/googletest/src"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/googletest"

  cd ../googlemock
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/gmock/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/gmock/src"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/gmock"

  sed -i 's|src/||' "${pkgdir}/usr/src/gmock/src/gmock-all.cc"

  python -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
  python -O -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
}

# vim: ts=2 sw=2 et:
