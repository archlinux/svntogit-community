# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-wav
epoch=1
pkgver=2.0.1
pkgrel=14
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
sha512sums=('27746034397fe87bcfb81a429350e234be5fe793ef37f1c4f58ab87c91ef11fec8c808874183e59b325228289d519f948dddd5c9587911f3ffca36ca53641f8d')

build() {
    cd "audioencoder.wav-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.wav-$pkgver"
    make DESTDIR="$pkgdir/" install
}

