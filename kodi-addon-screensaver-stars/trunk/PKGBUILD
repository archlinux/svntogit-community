# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-stars
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Starfield screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.stars'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.stars/archive/v$pkgver.tar.gz")

build() {
    cd "screensaver.stars-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.stars-$pkgver"
	make DESTDIR="$pkgdir/" install
}

sha512sums=('8eae14c604c6687d8703d5fe0c20b98a741f11944b8a0b7931a2bcfd84b0b60da91bfdb089b1eaa50a844dd6e25844d4725b2959ef439a93d1e2660a5cab332d')
