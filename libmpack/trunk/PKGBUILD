# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>

pkgname=libmpack
pkgver=1.0.5
pkgrel=3
pkgdesc="Simple implementation of msgpack in C"
arch=('x86_64')
url="https://github.com/libmpack/libmpack"
license=(MIT)
source=(https://github.com/libmpack/libmpack/archive/${pkgver}.tar.gz)
sha512sums=('6e30edafcacfb580b410bc6749ed7fe8f18b3be0cb98959339853e77bc3ec0cda6df08a0f1f22768cfc773458a2ea6bcef4f0421eea55cf56c58981d13711a04')

build() {
  cd "$srcdir/$pkgname-$pkgver"

  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  make DESTDIR="$pkgdir/" PREFIX=/usr install
}

# vim:set ts=2 sw=2 et:

