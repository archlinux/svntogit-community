# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=minisign
pkgver=0.8
pkgrel=2
pkgdesc="A dead simple tool to sign files and verify digital signatures."
arch=('x86_64')
url="https://github.com/jedisct1/minisign"
license=('custom:ISC')
depends=('libsodium')
makedepends=('cmake')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jedisct1/minisign/archive/$pkgver.tar.gz")
sha512sums=('79bf626d0c15e39ce3bdf53600038028c0b22904b648074bf516a9ea6962c9486c41244e80637a5fbac090cce1ed9b4b3d57b8a02632646e01b43aa413cd8bd9')

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
