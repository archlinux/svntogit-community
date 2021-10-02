# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=kquickimageeditor
pkgver=0.2.0
pkgrel=1
pkgdesc='QML image editing components'
license=(LGPL)
arch=(x86_64)
url='https://invent.kde.org/libraries/kquickimageeditor'
depends=(qt5-declarative)
makedepends=(extra-cmake-modules)
source=("https://download.kde.org/stable/$pkgname/$pkgname-$pkgver.tar.xz"{,.sig})
sha256sums=('3cfba775498e031f6963669ee0e4426d4fddd48a244b9583620de4d312ba92ca'
            'SKIP')
validpgpkeys=(B3ED0BAE371BEDA00717921D18F4795C1CE7042B) # Carl Schwan <carl@carlschwan.eu>

build() {
  cmake -B build -S $pkgname-$pkgver
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
