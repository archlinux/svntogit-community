# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-audioencoder-vorbis
epoch=1
pkgver=2.0.1
pkgrel=9
pkgdesc="Vorbis Audio Encoder add-on for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/audioencoder.vorbis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-audioencoder')
provides=('kodi-audioencoder-vorbis')
replaces=('kodi-audioencoder-vorbis')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/audioencoder.vorbis/archive/v$pkgver.tar.gz")
sha512sums=('ed560a014d135dc9bc57f0185afd3fc4636158309eb4029b0fa1392ef2109c7795902eb37ce051d99199e5834d530c67b63362fdfb9db500a27e10c39d49e1d9')

build() {
    cd "audioencoder.vorbis-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "audioencoder.vorbis-$pkgver"
    make DESTDIR="$pkgdir/" install
}

