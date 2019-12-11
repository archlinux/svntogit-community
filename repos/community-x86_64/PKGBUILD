# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-flac
epoch=1
pkgver=2.0.5
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
sha512sums=('4c6940be8c84f509a399ed22a38281259327371c7819cde4266ffd3712484664561a9bd3a5ecc8b51c0e45305f90114164f3aa2bc624c0d0d588b212bf28c750')

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

