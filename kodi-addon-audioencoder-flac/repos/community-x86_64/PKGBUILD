# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-flac
epoch=1
pkgver=2.0.4
_codename=Leia
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
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.flac/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d58913acc84b892049919c15fd5d82e46f4451eaf6f7993e36e66e1e390f14c86bf0633dfdf60f6751ea23b43b7e0b7a8d2fc7a1c28a87212c614fc16cf33056')

build() {
    cd "audioencoder.flac-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
	cd "audioencoder.flac-$pkgver-$_codename"
	make DESTDIR="$pkgdir/" install
}

