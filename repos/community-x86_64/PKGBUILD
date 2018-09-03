# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Alexandre Bique <bique.alexandre@gmail.com>
# Contributor: Louis R. Marascio <lrm@fitnr.com>
# Contributor: Cody Maloney <cmaloney@theoreticalchaos.com>

pkgbase=gtest
pkgname=('gtest' 'gmock')
pkgver=1.8.1
pkgrel=1
pkgdesc='Google Test - C++ testing utility'
url='https://github.com/google/googletest/'
arch=('x86_64')
license=('BSD')
makedepends=('python2' 'cmake' 'gcc-libs' 'sh')
options=(!makeflags)
source=(${pkgbase}-${pkgver}.tar.gz::https://github.com/google/googletest/archive/release-${pkgver}.tar.gz
        gtest-pkgconfig.patch
        gtest.pc.in
        gmock-install.patch
        gmock.pc.in)
sha512sums=('e6283c667558e1fd6e49fa96e52af0e415a3c8037afe1d28b7ff1ec4c2ef8f49beb70a9327b7fc77eb4052a58c4ccad8b5260ec90e4bceeac7a46ff59c4369d7'
            '7e9ad4cd470eaab7ed5fb1cce1d5721d40fc03a62b0c895b8f9657679ffa43f91b99800bb1e02a6c5c2d0a72e94bb8ea008aa6e74fdb1460b1326a84da5e9f91'
            'df3d23bc53c3b4ab5bacb4b6fad8823870b2ba6b86017e1e99067fb547533a649f2c8e8a8634e3583b344230e1afc280a047d41330cbc7510cfd0c5e843594c3'
            '2c2417c178485a590695f7d37b26fad3a1a1993fdc9a0c869c34fec83d51769b8057b4f67000e0585f61919c092175186252704a032e9b06bfc1f0e7c0b900f9'
            '3e4c2e96139292818d97b52536776b656bea30f119124dab4d5c2cb2f31098a3bfac928b74297f7c77229d3eb5fa3b734931c64d8bef2f867b585e43b390a59c')

prepare() {
  cd googletest-release-${pkgver}
  find -name '*.py' -exec sed -i 's|env python|env python2|g' {} \;

  msg2 "Preparing googletest..."
  (cd googletest
    autoreconf -fvi
    cp "${srcdir}/gtest.pc.in" .
    sed -r "s|(Version:) .+|\1 ${pkgver}|" -i gtest.pc.in
    patch -p1 < "${srcdir}/gtest-pkgconfig.patch"
    mkdir build
  )

  msg2 "Preparing googlemock..."
  patch -p1 < "${srcdir}/gmock-install.patch"
  (cd googlemock
    cp "${srcdir}/gmock.pc.in" .
    autoreconf -fvi
  )
}

build() {
  cd googletest-release-${pkgver}

  msg2 "Building googletest..."
  (cd googletest
    # this is odd but needed only to generate gtest-config.
    ./configure --prefix=/usr
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=/usr \
      -DBUILD_SHARED_LIBS=ON \
      -DCMAKE_SKIP_RPATH=ON ..
    make
  )

  msg2 "Building googlemock..."
  (cd googlemock
    ./configure --prefix=/usr --with-gtest --enable-external-gtest
    make
  )
}

package_gtest() {
  pkgdesc='Google Test - C++ testing utility based on the xUnit framework (like JUnit)'
  depends=('gcc-libs' 'sh')

  cd googletest-release-${pkgver}/googletest
  make -C build DESTDIR="${pkgdir}" install
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CHANGES CONTRIBUTORS -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 755 scripts/gtest-config -t "${pkgdir}/usr/bin"
  install -Dm 644 build/libgtest{,_main}.so -t "${pkgdir}/usr/lib"
  install -Dm 644 m4/gtest.m4 -t "${pkgdir}/usr/share/aclocal"
  install -Dm 644 cmake/* -t "${pkgdir}/usr/src/gtest/cmake"
  install -Dm 644 src/* -t "${pkgdir}/usr/src/gtest/src"
  install -d "${pkgdir}/usr/include"
  cp -r include/gtest -t "${pkgdir}/usr/include"

  # undo pkg-config patch so subprojects including this don't try to generate it
  patch -Rp1 < "${srcdir}/gtest-pkgconfig.patch"
  install -Dm 644 CMakeLists.txt -t "${pkgdir}/usr/src/gtest"
}

package_gmock() {
  pkgdesc='Google Mock - A library for writing and using C++ mock classes'
  depends=('python2' 'gtest' 'gcc-libs' 'sh')

  cd googletest-release-${pkgver}/googlemock
  make --trace -w -j1 DESTDIR="${pkgdir}" install
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CHANGES CONTRIBUTORS -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 755 scripts/gmock-config -t "${pkgdir}/usr/bin"
  install -Dm 644 include/gmock/internal/custom/* -t "${pkgdir}/usr/include/gmock/internal/custom"
}

# vim: ts=2 sw=2 et:
