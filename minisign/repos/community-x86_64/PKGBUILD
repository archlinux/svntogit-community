# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=minisign
pkgver=0.10
pkgrel=1
pkgdesc="A dead simple tool to sign files and verify digital signatures."
arch=('x86_64')
url="https://github.com/jedisct1/minisign"
license=('custom:ISC')
depends=('libsodium')
makedepends=('cmake')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jedisct1/minisign/archive/$pkgver.tar.gz")
sha512sums=('6a38500ed896c17b100bca47443f9806debe6e44d3ce09189f5f8913a41d4913434397175d1caa770fb0cc0918078dfc71c01b82b9bf919fdfba00434f4ce100')

prepare() {
  mkdir -p build
}

build() {
  cd build

  cmake ../minisign-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_BUILD_TYPE=Release
  make
}

package() {
  make -C build DESTDIR="$pkgdir" install

  install -Dm644 minisign-$pkgver/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
