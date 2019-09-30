# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-stars
epoch=1
pkgver=2.1.2
_codename=Leia
pkgrel=6
pkgdesc="Starfield screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.stars'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.stars/archive/$pkgver-$_codename.tar.gz")
sha512sums=('2c3cd1d9ae934b091762a64651d2db09ae8c96aadae676bf0cec0232b6da506567f903c580d32dd28ab8d275e76e946ffb63a03f6cd8698e277704c08123d78d')

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

