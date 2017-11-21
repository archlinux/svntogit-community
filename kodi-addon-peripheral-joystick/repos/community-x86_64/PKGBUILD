# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-peripheral-joystick
pkgver=1.3.4
pkgrel=1
pkgdesc="Joystick support for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/peripheral.joystick'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-peripheral')
depends=('kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/peripheral.joystick/archive/v$pkgver.tar.gz")
sha512sums=('1f5a7ae946c788c72562001b365e4de631288d4bc31d7960d0172c6e381dee221ec6b099619999d12e14fff67893a2d5cf29ecf90b2d541cd0e1f969233f1df2')

build() {
    cd "peripheral.joystick-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "peripheral.joystick-$pkgver"
	make DESTDIR="$pkgdir/" install
}

