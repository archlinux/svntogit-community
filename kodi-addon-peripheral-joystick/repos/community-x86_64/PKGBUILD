# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-peripheral-joystick
pkgver=1.3.1
pkgrel=1
pkgdesc="Joystick support for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/peripheral.joystick'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-peripheral')
depends=('kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/peripheral.joystick/archive/v$pkgver.tar.gz")
sha512sums=('5f4ad834bbbcf725225220fc416e53b70214aa9062107a585f92d344d05f2d63d2df4c34d8a55be08d2b6f589c9332fa7a4ce35da54eadd278257bb8bb7f2ac3')

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

