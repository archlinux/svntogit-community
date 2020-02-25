# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-biogenesis
epoch=1
pkgver=2.2.3
_codename=Leia
pkgrel=1
pkgdesc="BioGenesis screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.biogenesis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.biogenesis/archive/$pkgver-$_codename.tar.gz")
sha512sums=('62f96e318766d609110fdddd3d56a56b7402630a137a7ded051a60b042c9e8f5e7b414d5d48d760c16cc272bbaa5f664478ed7beec216e2d8f6ce5b363ea4f9c')

build() {
    cd "screensaver.biogenesis-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "screensaver.biogenesis-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

