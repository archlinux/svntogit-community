# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-stars
epoch=1
pkgver=2.1.4
_codename=Leia
pkgrel=7
pkgdesc="Starfield screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.stars'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.stars/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f821d8b9562ab195fac3d955c9b2e7f304cbc0f201d14923ddb1cb612732f99c59ff04faed7558a80bb9a13d6564a1fd9fa1e3c9ae62699255ea72126967a990')

build() {
    cd "screensaver.stars-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.stars-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

