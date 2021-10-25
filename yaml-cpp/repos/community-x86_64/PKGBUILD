# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: David Runge <dvzrv@archlinux.org>
# Contributor: Markus Martin <markus@archwyrm.net>

pkgname=yaml-cpp
pkgver=0.7.0
pkgrel=2
pkgdesc="YAML parser and emitter in C++, written around the YAML 1.2 spec"
url="https://github.com/jbeder/yaml-cpp"
arch=('x86_64')
license=('MIT')
depends=('gcc-libs' 'glibc')
provides=('libyaml-cpp.so')
makedepends=('cmake' 'ninja')
source=("https://github.com/jbeder/yaml-cpp/archive/yaml-cpp-${pkgver}.tar.gz"
        https://patch-diff.githubusercontent.com/raw/jbeder/yaml-cpp/pull/1037.patch)
sha512sums=('2de0f0ec8f003cd3c498d571cda7a796bf220517bad2dc02cba70c522dddde398f33cf1ad20da251adaacb2a07b77844111f297e99d45a7c46ebc01706bbafb5'
            'c20d5e9393496052c3326d78555345b83a2345831d4cbfec8cf50f9576f2731ddc456148815b23dba3765b61a1a69b0c05c9618f91751dad124dbe8f7ca19609')

prepare() {
  cd "${pkgname}-${pkgname}-${pkgver}"
  patch -Np1 -i "${srcdir}"/1037.patch
}

build() {
  cd "${pkgname}-${pkgname}-${pkgver}"
  cmake -GNinja \
        -Bbuild \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DBUILD_SHARED_LIBS=ON \
        -DYAML_BUILD_SHARED_LIBS=ON \
        -DCMAKE_BUILD_TYPE=Release
  ninja -C build
}

check() {
  cd "${pkgname}-${pkgname}-${pkgver}"
  ninja -C build test
  build/test/yaml-cpp-tests
}

package() {
  cd "${pkgname}-${pkgname}-${pkgver}"
  DESTDIR="$pkgdir" ninja -C build install
  install -vDm 644 {CONTRIBUTING,README}.md -t "$pkgdir/usr/share/doc/$pkgname"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
  rm -rf "${pkgdir}"/usr/{lib,lib/pkgconfig,include}/*{gtest,gmock}*
  rm -rf "${pkgdir}"/usr/lib/cmake/GTest
}
