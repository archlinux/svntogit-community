# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-lame
epoch=1
pkgver=2.0.1
pkgrel=14
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
sha512sums=('eb780f31e96a0c745cb2598212aab39a065cc85b186b579ba2ace4732640588dabf9a6ef2e6ee57ddd793a2790cab0b8c2a1068714b80ecbfa4ae4a6eaf2f4b1')

build() {
    cd "audioencoder.lame-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.lame-$pkgver"
    make DESTDIR="$pkgdir/" install
}

