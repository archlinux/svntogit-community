# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-flac
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="FLAC Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.flac'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-flac')
replaces=('kodi-audioencoder-flac')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.flac/archive/v$pkgver.tar.gz")
sha512sums=('1a89cd5cd02305b4121582e06a7e88dd745133fa0676d01a9c5f15af025050875a9fa59e74efa71bc5a9d85cb845050edecac507ccd8f4f1f3300016e74331b3')

build() {
	cd "audioencoder.flac-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "audioencoder.flac-$pkgver"
	make DESTDIR="$pkgdir/" install
}

