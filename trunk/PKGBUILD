# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pyro
epoch=1
pkgver=3.0.0
_codename=Leia
pkgrel=6
pkgdesc="Pyro screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.pyro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.pyro/archive/$pkgver-$_codename.tar.gz")
sha512sums=('92335e156950f7da5800dc9c9fd57262a2d608d63cb2015e3f5711686b657930f05651a35e043480ed64f40cb34a3228c44b6c641b63a8d0438e0944abc09515')

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

