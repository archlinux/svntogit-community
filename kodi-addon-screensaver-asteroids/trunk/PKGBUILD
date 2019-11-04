# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
epoch=1
pkgver=2.3.1
_codename=Leia
pkgrel=1
pkgdesc="Asteroids screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.asteroids'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.asteroids/archive/$pkgver-$_codename.tar.gz")
sha512sums=('e683eba7e03c4f150f94b78587470b49f1be1cf38817a59de0d08477725ccd1d5af08f9f336566b633d9cde5f1207ec0fc90796af0d8af2148929898c0de7d3e')

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

