# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: FadeMind <fademind@gmail.com>
# Contributor: Zatherz <zatherz at linux dot pl>

pkgname=qt5ct
pkgver=1.7
pkgrel=1
pkgdesc='Qt5 Configuration Utility'
arch=(x86_64)
url='https://qt5ct.sourceforge.io/'
license=(BSD)
depends=(qt5-svg)
makedepends=(cmake qt5-tools)
source=(https://downloads.sourceforge.net/project/$pkgname/$pkgname-$pkgver.tar.bz2)
sha256sums=('ed58546a6e4c50dfed1b9ff6a148d4a468fe9b4d7b5b2727b96501de2955b8d7')

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/COPYING "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
} 
