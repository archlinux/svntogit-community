# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Jan Alexander Steffens (heftig) <jan.steffens@gmail.com>
# Contributor: Alexandre Bique <bique.alexandre@gmail.com>
# Contributor: Louis R. Marascio <lrm@fitnr.com>
# Contributor: Cody Maloney <cmaloney@theoreticalchaos.com>

pkgbase=gtest
pkgname=('gtest' 'gmock')
pkgver=1.8.1
pkgrel=2
pkgdesc='Google Test - C++ testing utility'
url='https://github.com/google/googletest'
arch=('x86_64')
license=('BSD')
makedepends=('python2' 'cmake' 'gcc-libs' 'sh' 'ninja')
_srcname=googletest-release-${pkgver}
source=(${_srcname}.tar.gz::https://github.com/google/googletest/archive/release-${pkgver}.tar.gz
        gtest-1.8.1-libversion.patch
        gtest-1.8.1-null-pointer.patch)
sha512sums=('e6283c667558e1fd6e49fa96e52af0e415a3c8037afe1d28b7ff1ec4c2ef8f49beb70a9327b7fc77eb4052a58c4ccad8b5260ec90e4bceeac7a46ff59c4369d7'
            '99667910ddb55f495b15b51d4a21b878f2c2c4e72e2ce7054d6491274e35002e3e793e0c86e5c6d774a0301a7af8c5d5175ff910e12bf6c71f008a6368e33c92'
            'afa75f975d8aed453c901245dae753939958d8b72e3e5c52995efe7980f44de4fd1ea08f1b0a4cc927443d858de0a1fe34a919512ce05ae443bfb9600b08f029')

prepare() {
  cd ${_srcname}

  # https://src.fedoraproject.org/rpms/gtest/tree/master
  patch -Np1 -i ../gtest-1.8.1-libversion.patch
  patch -Np1 -i ../gtest-1.8.1-null-pointer.patch

  find . -name '*.py' -exec sed -i '1s|python$|&2|g' {} +
}

build() {
  mkdir build build-ac
  cd build

  cmake -G Ninja ../${_srcname} \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DBUILD_SHARED_LIBS=ON \
    -DPython_ADDITIONAL_VERSIONS=2.7 \
    -Dgtest_build_tests=ON
  cmake --build .

  # Only for g{test,mock}-config
  cd ../${_srcname}/googletest
  autoreconf -fvi
  ./configure --prefix=/usr
  cd ../googlemock
  autoreconf -fvi
  ./configure --prefix=/usr
}

check() {
  cmake --build build --target test
}

package_gtest() {
  pkgdesc='Google Test - C++ testing utility based on the xUnit framework (like JUnit)'
  depends=('gcc-libs' 'sh')

  DESTDIR="${pkgdir}" cmake --build build --target install

  # Shouldn't be present
  find "${pkgdir}" -name '*.pump' -printf 'Removing %P\n' -delete

  # Split gmock
  mkdir -p gmock/{include,lib/pkgconfig}
  mv "${pkgdir}"/usr/include/gmock gmock/include/
  mv "${pkgdir}"/usr/lib/libgmock* gmock/lib/
  mv "${pkgdir}"/usr/lib/pkgconfig/gmock* gmock/lib/pkgconfig/

  cd ${_srcname}/googletest
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CHANGES CONTRIBUTORS -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 755 scripts/gtest-config -t "${pkgdir}/usr/bin"
  install -Dm 644 m4/gtest.m4 -t "${pkgdir}/usr/share/aclocal"
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/gtest/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/gtest/src"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/gtest"
}

package_gmock() {
  pkgdesc='Google Mock - A library for writing and using C++ mock classes'
  depends=('python2' 'gtest' 'gcc-libs' 'sh')

  mv gmock "${pkgdir}/usr"

  cd ${_srcname}/googlemock
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CHANGES CONTRIBUTORS -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 755 scripts/gmock-config -t "${pkgdir}/usr/bin"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/gmock"
  install -Dm 644 scripts/generator/{*.py,LICENSE,README*} -t "${pkgdir}/usr/share/gmock/generator"
  install -Dm 644 scripts/generator/cpp/* -t "${pkgdir}/usr/share/gmock/generator/cpp"

  sed -i 's|src/||' "${pkgdir}/usr/src/gmock/gmock-all.cc"

  python2 -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
  python2 -O -m compileall -d /usr/share/gmock "${pkgdir}/usr/share/gmock"
}

# vim: ts=2 sw=2 et:
