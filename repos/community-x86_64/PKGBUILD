# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-rsxs
epoch=1
pkgver=1.4.0
pkgrel=1
pkgdesc="RSXS screensaver add-ons for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/screensavers.rsxs'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensavers.rsxs/archive/v$pkgver.tar.gz")

build() {
    cd "screensavers.rsxs-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensavers.rsxs-$pkgver"
	make DESTDIR="$pkgdir/" install
}

sha512sums=('95d553e54be91b914b40d4616d2a6a127404215ceb4fbdf40abc4b6c9d981b33681dbe88c6def34d0bf80a8c0188c59d3760a5804a5189dce1257e5242568497')
