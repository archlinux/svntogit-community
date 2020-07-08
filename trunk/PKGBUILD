# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-vorbis
epoch=1
pkgver=2.0.4
_codename=Leia
pkgrel=7
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
sha512sums=('df618e078d1b0aa3f9b6cbca87288908058f4de13e52056d66239e9606c67a31a84734d8d650520920b8a9e0dfbd1c031aa81e2d1ece1316c11fbd59a6a8d8a2')

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

