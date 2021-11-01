# Maintainer: Jelle van der Waa <jelle@archlinux.org>

pkgname=cjson
pkgver=1.7.15
pkgrel=1
pkgdesc="Ultralightweight JSON parser in ANSI C"
arch=(x86_64)
license=("MIT")
makedepends=("cmake")
url="https://github.com/DaveGamble/cJSON"
source=("$pkgname-$pkgver.tar.gz::https://github.com/DaveGamble/cJSON/archive/v$pkgver.tar.gz")
sha512sums=('0b32a758c597fcc90c8ed0af493c9bccd611b9d4f9a03e87de3f7337bb9a28990b810befd44bc321a0cb42cbcd0b026d45761f9bab7bd798f920b7b6975fb124')

build() {
  cmake -B build -S "cJSON-${pkgver}" -DENABLE_CJSON_UTILS=On -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=lib
  make -C build
}

check() {
  make -C build check
}

package() {
  make -C build DESTDIR="${pkgdir}" install
  install -Dm644 "$srcdir/cJSON-$pkgver/LICENSE" \
    "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
