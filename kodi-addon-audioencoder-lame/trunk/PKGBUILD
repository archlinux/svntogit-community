# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-lame
_commit=ffaf9cb
pkgver=20160219.ffaf9cb
pkgrel=2
pkgdesc="LAME Audio Encoder add-on for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/xbmc/audioencoder.lame'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-lame')
replaces=('kodi-audioencoder-lame')
depends=('kodi' 'lame')
makedepends=('git' 'cmake')
source=("$pkgname::git://github.com/xbmc/audioencoder.lame.git#commit=$_commit")
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

