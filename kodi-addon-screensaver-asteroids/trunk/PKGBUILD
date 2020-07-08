# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
epoch=1
pkgver=2.3.2
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
sha512sums=('1ea720ba96e65e2d63984ece928f40d60eaacd207cfa64979f1fb38e779957bbd91f41df0e0dcb0bad1b3efbb5dd9be17f2a06bcbeb3c06e7a386c07e99d22db')

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

