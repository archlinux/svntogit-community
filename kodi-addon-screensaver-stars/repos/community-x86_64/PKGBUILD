# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-stars
epoch=1
pkgver=2.1.1
_codename=Leia
pkgrel=5
pkgdesc="Starfield screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.stars'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.stars/archive/$pkgver-$_codename.tar.gz")
sha512sums=('f09195c4f471389d8fad009bbb8b38f2a58dd25f2818278b14b2903b0fe118f0db608d7c7f113b5dd1666f9c041ee03f3944b5dd3af76f704410207a9db2b86f')

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

