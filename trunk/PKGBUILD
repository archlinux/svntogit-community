# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-peripheral-joystick
pkgver=1.3.2
pkgrel=1
pkgdesc="Joystick support for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/peripheral.joystick'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-peripheral')
depends=('kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/peripheral.joystick/archive/v$pkgver.tar.gz")
sha512sums=('9aa2e5d1af51b83abc0691fb9f6c7603d07c37b61fde898e2010d6370b9dca44275bd53caa2252479128360bc97eb8bd904d268a9c0cab7f2958c0b31f64ba1f')

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

