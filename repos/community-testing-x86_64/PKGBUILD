# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pyro
epoch=1
pkgver=2.0.0
_codename=Leia
pkgrel=9
pkgdesc="Pyro screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.pyro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.pyro/archive/$pkgver-$_codename.tar.gz")
sha512sums=('383fd40fc2bde9a1fe52126300b6279ec78ceab773bd6a763c8b72c3d3ed9b04e5b15eaa0de6da34af7e1d86046807e4734f75e524fa8335bf18cc8bc3965360')

build() {
    cd "screensaver.pyro-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.pyro-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

