# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-greynetic
epoch=1
pkgver=2.1.0
_codename=Leia
pkgrel=9
pkgdesc="Greynetic screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.greynetic'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.greynetic/archive/$pkgver-$_codename.tar.gz")
sha512sums=('32b01e4ca337db187e557a6d40def26d31d8840063fdcafc157572ac00515e29acebb031abe675777ac8c2c63eee3284a97442c67c162d540346cd8be71a7a1f')

build() {
    cd "screensaver.greynetic-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.greynetic-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

