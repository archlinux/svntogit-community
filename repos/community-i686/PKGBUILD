# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-peripheral-joystick
pkgver=1.2.1
pkgrel=1
pkgdesc="Joystick support for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/peripheral.joystick'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-peripheral')
depends=('kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/peripheral.joystick/archive/v$pkgver.tar.gz")
sha512sums=('af86bf8c7e8f7a975f5282a4b4c1d36027552857b31f28bbed03eac0b8e1059bb46f284bf5461c261f0f8be56e2e5a221eb9f916aeff6567fcebc459e34398d6')

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

