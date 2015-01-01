# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-audioencoder-wav
pkgver=20141102.40aaedf
pkgrel=2
pkgdesc="kodi audioencoder addon for wav"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/audioencoder.wav'
license=('GPL')
groups=('kodi-addons')
depends=('kodi')
makedepends=('git' 'cmake')
source=("$pkgname::git://github.com/xbmc/audioencoder.wav.git")
sha256sums=('SKIP')

pkgver() {
	cd "$pkgname"
	git log -1 --date=short --format="%cd.%h" | tr -d '-'
}

build() {
	cd "$pkgname"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "$pkgname"
	make DESTDIR="$pkgdir/" install
}

