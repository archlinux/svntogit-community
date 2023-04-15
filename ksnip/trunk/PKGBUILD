# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: dracorp aka Piotr Rogoza <piotr.r.public at gmail.com>

pkgname=ksnip
pkgver=1.10.1
pkgrel=1
pkgdesc='Qt-based screenshot tool that provides many annotation features'
arch=('x86_64')
url='https://github.com/ksnip/ksnip'
license=('GPL2')
depends=('hicolor-icon-theme' 'kimageannotator' 'qt5-x11extras')
makedepends=('cmake' 'extra-cmake-modules' 'ninja' 'qt5-tools')
source=("https://github.com/ksnip/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha256sums=('41fa6a54b0a88095ccdf7f8f3a96617e91fb15dcedae2aadaf2ee24677e9a88c')

build() {
  cmake -S $pkgname-$pkgver -B build -G Ninja -DCMAKE_INSTALL_PREFIX='/usr'
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
