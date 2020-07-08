# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pingpong
epoch=1
pkgver=2.1.2
_codename=Leia
pkgrel=7
pkgdesc="Ping-pong screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.pingpong'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'glm')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.pingpong/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d7a1b316920a4ecea88462c6ade886f8bebf35d4b2be7108eca8fc929838c01b02a1f7cc1dce5ce89f677e84cea7cdd7eb259cc23fb70b6760bf2eb57d6a9e5d')

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

