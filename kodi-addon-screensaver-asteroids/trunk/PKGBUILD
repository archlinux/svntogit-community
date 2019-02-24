# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
epoch=1
pkgver=2.2.1
_codename=Leia
pkgrel=3
pkgdesc="Asteroids screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.asteroids'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.asteroids/archive/$pkgver-$_codename.tar.gz")
sha512sums=('552190ae2cb9a07ed5a506c40b92639bca07dbffe191f333ead391663509a53a07bf72f2ab451a37445ff5175532cf5f0f7eac0711287b2012df244460b12c07')

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

