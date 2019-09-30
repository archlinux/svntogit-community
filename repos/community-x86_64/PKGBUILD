# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-greynetic
epoch=1
pkgver=2.2.1
_codename=Leia
pkgrel=6
pkgdesc="Greynetic screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.greynetic'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.greynetic/archive/$pkgver-$_codename.tar.gz")
sha512sums=('d8c69efad259d137e9d67a526f540b4704e62bd24e0f307ec54fe08a3d3e57112756c7c32a4e65eb7240c528318e7920c52cc0c9a3a1bd1a67ee455254e5ff58')

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

