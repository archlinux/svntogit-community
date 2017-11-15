# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pyro
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Pyro screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.pyro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.pyro/archive/v$pkgver.tar.gz")
sha512sums=('93cbf40393dc2c50c927daffbdc10756c4a8e4a9a960e07edd6841ae4b0ac5c49beb097ce0710ca38720963e77859b7ed0198dc611c6990a73e066c8ee91bcb2')

build() {
    cd "screensaver.pyro-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.pyro-$pkgver"
	make DESTDIR="$pkgdir/" install
}

