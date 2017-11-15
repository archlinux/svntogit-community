# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-lame
epoch=1
pkgver=1.2.0
pkgrel=1
pkgdesc="LAME Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.lame'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-lame')
replaces=('kodi-audioencoder-lame')
depends=('kodi' 'lame')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.lame/archive/v$pkgver.tar.gz")
sha512sums=('4f4ce910f9831e6f86615b0dc97c77ce60a834d5fd4e000976c6cd84d411eaa65e1a9b8a38edae7ff7c52d1a24c99f794b65c76432cfe4eeb286050e495190c1')

build() {
	cd "audioencoder.lame-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "audioencoder.lame-$pkgver"
	make DESTDIR="$pkgdir/" install
}

