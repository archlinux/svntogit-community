# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-lame
epoch=1
pkgver=2.0.4
_codename=Leia
pkgrel=7
pkgdesc="LAME Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.lame'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-lame')
replaces=('kodi-audioencoder-lame')
depends=('kodi' 'lame')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.lame/archive/$pkgver-$_codename.tar.gz")
sha512sums=('8b57d20c2d02ec7148a83ab7af78eaf92b600a40faa666c4f26b5acb59838ade54f026dc3869b23fc79511fc5901acca5322d2f04336fc8d4f545f5d7c04cb2c')

build() {
    cd "audioencoder.lame-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.lame-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

