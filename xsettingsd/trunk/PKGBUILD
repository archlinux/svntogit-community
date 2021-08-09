# Maintainer: Alad Wenter <alad@archlinux.org>

pkgname=xsettingsd
pkgver=1.0.2
pkgrel=1
pkgdesc="Provides settings to X11 applications via the XSETTINGS specification"
arch=('x86_64')
url="https://github.com/derat/xsettingsd"
license=('custom:BSD')
depends=('libx11' 'gcc-libs')
makedepends=('cmake')
source=(https://github.com/derat/xsettingsd/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('69b5d1987608d1b5f2a0085f2f88cc55936a99b92279118e655d665ebb5e50d3')

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build
  install -Dm644 $pkgname-$pkgver/COPYING -t "$pkgdir"/usr/share/licenses/$pkgname
}
