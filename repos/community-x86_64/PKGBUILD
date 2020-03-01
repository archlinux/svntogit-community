# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-stars
epoch=1
pkgver=2.1.3
_codename=Leia
pkgrel=2
pkgdesc="Starfield screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.stars'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.stars/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d4b6189f1c4acec4df6488bb262a0cfd0375b01d5aa3f65df0ff26d6e9061a403e25c67145d7fd76765dc2df7432ba163249453ff48a932029999182bd370b2d')

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

