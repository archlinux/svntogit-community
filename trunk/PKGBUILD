# Maintainer: Christian Rebischke <chris.rebischke at archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Jonathan Steel <jsteel at archlinux.org>
# Contributor: Yunhui Fu <yhfudev@gmail.com>

pkgname=rapidjson
pkgver=1.1.0
pkgrel=5
pkgdesc="Fast JSON parser/generator for C++ with both SAX/DOM style API"
arch=('any')
url="https://github.com/miloyip/rapidjson"
license=('MIT')
makedepends=('cmake')
checkdepends=('gtest' 'valgrind')
source=(https://github.com/miloyip/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha512sums=('2e82a4bddcd6c4669541f5945c2d240fb1b4fdd6e239200246d3dd50ce98733f0a4f6d3daa56f865d8c88779c036099c52a9ae85d47ad263686b68a88d832dff')

prepare() {
  cd $pkgname-$pkgver
  find -name CMakeLists.txt | xargs sed -e 's|-Werror||' -i # Don't use -Werror
}

build () {
  cd $pkgname-$pkgver

  mkdir -p build
  cd build

  cmake \
      -DCMAKE_BUILD_TYPE=None \
      -DCMAKE_INSTALL_PREFIX:PATH=/usr \
      -DRAPIDJSON_HAS_STDSTRING=ON \
      -DRAPIDJSON_BUILD_CXX11=ON \
      -DRAPIDJSON_ENABLE_INSTRUMENTATION_OPT=OFF \
      -DDOC_INSTALL_DIR=/usr/share/doc/${pkgname} \
      ..

  make
}

check() {
  cd $pkgname-$pkgver/build
  ctest -j 2 -V
}

package() {
  cd $pkgname-$pkgver

  DESTDIR="$pkgdir" make -C build install

  install -Dm644 license.txt "$pkgdir"/usr/share/licenses/$pkgname/license.txt
}

# vim: ts=2 sw=2 et:
