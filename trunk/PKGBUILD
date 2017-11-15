# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asterwave
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="AsterWave screensaver for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/screensaver.asterwave'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'soil')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.asterwave/archive/v$pkgver.tar.gz")
sha256sums=('48cd459b60b2407b8bae9107760a013d04ee29e00fddbce9550291896d42ef64')

build() {
    cd "screensaver.asterwave-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1
    make
}

package() {
    cd "screensaver.asterwave-$pkgver"
    make DESTDIR="$pkgdir/" install
}

