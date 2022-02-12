# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=plasma5-applets-window-buttons
pkgver=0.11.1
pkgrel=1
pkgdesc='Plasma 5 applet in order to show window buttons in your panels'
arch=(x86_64)
url='https://github.com/psifidotos/applet-window-buttons'
license=(GPL)
depends=(plasma-workspace)
makedepends=(extra-cmake-modules)
conflicts=(libappletdecoration)
replaces=(libappletdecoration)
source=(https://github.com/psifidotos/applet-window-buttons/archive/$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('0588a3bba77206766549139b4bee1a08b7be7a7113e658f746709b9ee4d3017a')
options=(debug)

build() {
  cmake -B build -S applet-window-buttons-$pkgver
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
