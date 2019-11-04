# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-vorbis
epoch=1
pkgver=2.0.3
_codename=Leia
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
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.vorbis/archive/$pkgver-$_codename.tar.gz")
sha512sums=('9c68cb84ce2cc207b81b98306615425f85054f9e8ad731512a9844521145e1cdda936ede4a6302e0d0a76094aeacb4d60732b375ae1c85705d5528804d42eecc')

build() {
    cd "audioencoder.vorbis-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.vorbis-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

