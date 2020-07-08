# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-wav
epoch=1
pkgver=2.0.3
_codename=Leia
pkgrel=7
pkgdesc="WAV Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.wav'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-wav')
replaces=('kodi-audioencoder-wav')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.wav/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f6b444483808b9e75426cd8b3252c4b3ed57811d9f1433d851d3cd6b3168f376bdfa2311aa3797642450b955ff8d231e40c7c49ad03a5f2b1b3e0679ec3a8617')

build() {
    cd "audioencoder.wav-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.wav-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

