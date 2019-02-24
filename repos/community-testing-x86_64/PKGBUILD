# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-biogenesis
epoch=1
pkgver=2.2.0
_codename=Leia
pkgrel=3
pkgdesc="BioGenesis screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.biogenesis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.biogenesis/archive/$pkgver-$_codename.tar.gz")
sha512sums=('31c3ac301b85432ea3f34fe01e33ce494cd93a49ccea2f2c41d98dafaa6420d16dc9e84aebd01183786b94bc744c3cee91d64a67d930bbb6ff38d7a47161b86b')

build() {
    cd "screensaver.biogenesis-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.biogenesis-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

