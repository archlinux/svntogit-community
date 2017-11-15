# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-vorbis
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Vorbis Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.vorbis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-vorbis')
replaces=('kodi-audioencoder-vorbis')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.vorbis/archive/v$pkgver.tar.gz")
sha512sums=('db07cead7c814003ce231e650b9e66718b9dc3860363f5d1019e73ba3763b1e8d6dd68d0e4f37b3f0eafd6504b60f69ddd7414f8e790956036a350196a360408')

build() {
	cd "audioencoder.vorbis-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "audioencoder.vorbis-$pkgver"
	make DESTDIR="$pkgdir/" install
}

