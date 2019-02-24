# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-matrixtrails
epoch=1
pkgver=2.2.0
_codename=Leia
pkgrel=9
pkgdesc="Matrix trails screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.matrixtrails'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'soil')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.matrixtrails/archive/v$pkgver-$_codename.tar.gz")
sha512sums=('edfbf1d02266450029a3dbd693f48227a0472dae6d561e12ba291563d9a75ca54bd2d7d1c25358114a0d095e3bfe874352735b457677815bad36e2d36999fed1')

build() {
    cd "screensaver.matrixtrails-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.matrixtrails-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

