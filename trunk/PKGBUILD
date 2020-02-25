# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pyro
epoch=1
pkgver=3.0.1
_codename=Leia
pkgrel=1
pkgdesc="Pyro screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.pyro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.pyro/archive/$pkgver-$_codename.tar.gz")
sha512sums=('bf2b248d2448342cd4b4e1b7c8b77ff1391050221a6c229f6db0e21cd7b9192ee925dedddbe2361b8cc2a2a943fbf53670f2d3832bff5cfbb29dea08896c9acb')

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

