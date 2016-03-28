# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-wav
_commit=a12bcd1
pkgver=20160219.a12bcd1
pkgrel=2
pkgdesc="WAV Audio Encoder add-on for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/audioencoder.wav'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-wav')
replaces=('kodi-audioencoder-wav')
depends=('kodi')
makedepends=('git' 'cmake')
source=("$pkgname::git://github.com/xbmc/audioencoder.wav.git#commit=$_commit")
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

