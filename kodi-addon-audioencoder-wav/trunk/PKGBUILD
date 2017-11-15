# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-wav
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="WAV Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.wav'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-wav')
replaces=('kodi-audioencoder-wav')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.wav/archive/v$pkgver.tar.gz")
sha512sums=('002894dfebf427a86419f211f67abb34f68286573434272c39033ee281ad63d53acbe1d9288acd49abc991c770c577347512e018bebd627e0f722f300e961d85')

build() {
	cd "audioencoder.wav-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "audioencoder.wav-$pkgver"
	make DESTDIR="$pkgdir/" install
}

