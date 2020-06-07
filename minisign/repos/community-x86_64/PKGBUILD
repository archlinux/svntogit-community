# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=minisign
pkgver=0.9
pkgrel=1
pkgdesc="A dead simple tool to sign files and verify digital signatures."
arch=('x86_64')
url="https://github.com/jedisct1/minisign"
license=('custom:ISC')
depends=('libsodium')
makedepends=('cmake')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jedisct1/minisign/archive/$pkgver.tar.gz")
sha512sums=('7970f3e72ff759f3f02416de5d6035e1c8dd4e92ea718083cc5091c7e2355b59c4e178c60ca934985ba1e1afcd970967d4fb39a434ba54b140f3fc9be661253d')

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
