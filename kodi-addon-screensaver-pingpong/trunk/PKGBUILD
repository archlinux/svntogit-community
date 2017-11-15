# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pingpong
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Ping-pong screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.pingpong'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.pingpong/archive/v$pkgver.tar.gz")
sha512sums=('304bb57cb4d5a9807ced12ad1503f7a1be0f57b2ccc8a024651dcdba83ee17fb1b3adde1799b62d41c0ad2fc75ec0757dc06492c9b3adb5b89e6ef77a63856b7')

build() {
    cd "screensaver.pingpong-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.pingpong-$pkgver"
	make DESTDIR="$pkgdir/" install
}

