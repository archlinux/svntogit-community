# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-greynetic
epoch=1
pkgver=2.2.2
_codename=Leia
pkgrel=1
pkgdesc="Greynetic screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.greynetic'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.greynetic/archive/$pkgver-$_codename.tar.gz")
sha512sums=('2ff75111db2df696055bd7b5d447662bae8871f05750f9753f646d9167d57d694442efe59ec277c0de0b064d6f5ab0d73f3c8cc1d1e918d065e35646d3311b41')

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

