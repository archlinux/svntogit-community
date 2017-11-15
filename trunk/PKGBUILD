# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-matrixtrails
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Matrix trails screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.matrixtrails'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'soil')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.matrixtrails/archive/v$pkgver.tar.gz")

build() {
    cd "screensaver.matrixtrails-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.matrixtrails-$pkgver"
	make DESTDIR="$pkgdir/" install
}

sha512sums=('e5b26a4065d98ad6923908fb905ebf591202e93ec03ef7ff3c5eea1bec92e6ea8a487ebaef331beffa7c6e6dadba7596711999cf4bb9677f0b5afe069eb3c620')
