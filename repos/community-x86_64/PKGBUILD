# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-wav
epoch=1
pkgver=2.0.2
_codename=Leia
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
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.wav/archive/$pkgver-$_codename.tar.gz")
sha512sums=('8e4de58bf6b7cc79c4bb24ed9f0906632f34a20c0a17010b4a5e32934d03414840b6a9d0db5b88975b5da2dd675cd743acb64288e2a3e338090f52df9fb228c9')

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

