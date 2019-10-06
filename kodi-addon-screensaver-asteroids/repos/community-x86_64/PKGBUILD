# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
epoch=1
pkgver=2.3.0
_codename=Leia
pkgrel=7
pkgdesc="Asteroids screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.asteroids'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.asteroids/archive/$pkgver-$_codename.tar.gz")
sha512sums=('9f4c45560b529c91cb35c4941bb2db2570de3de34b4fced8ab0172b02596c282e54cce05f4c1482fc65652a98b050856a7a31395e6144a3dcb164964dbe6fe36')

build() {
    cd "screensaver.asteroids-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.asteroids-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

