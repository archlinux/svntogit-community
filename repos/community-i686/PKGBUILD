# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
epoch=1
pkgver=1.1.2
pkgrel=1
pkgdesc="Asteroids screensaver for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/screensaver.asteroids'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.asteroids/archive/v$pkgver.tar.gz")
sha512sums=('96c760d7ad84d1676a621156a3b3220204783155335a4e7314b094f29bb21c0ddfc98309c0a21c07014f2d6c3ade0fc88eee2af7b84a5997d44190b73cf8783b')

build() {
    cd "screensaver.asteroids-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.asteroids-$pkgver"
	make DESTDIR="$pkgdir/" install
}

