# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pingpong
epoch=1
pkgver=2.1.1
_codename=Leia
pkgrel=9
pkgdesc="Ping-pong screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.pingpong'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.pingpong/archive/$pkgver-$_codename.tar.gz")
sha512sums=('388b5c2980c6001650b0147e21cf7d3baacc78f1d94b82b1f96b12a5ea5c420808a70500779b707138efea0c1c7cfea12c179b60d5f76eaf7f821d48e03e0d53')

build() {
    cd "screensaver.pingpong-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.pingpong-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

