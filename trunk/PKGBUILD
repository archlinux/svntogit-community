# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-biogenesis
epoch=1
pkgver=2.2.2
_codename=Leia
pkgrel=8
pkgdesc="BioGenesis screensaver for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/screensaver.biogenesis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/screensaver.biogenesis/archive/$pkgver-$_codename.tar.gz")
sha512sums=('ed79b7f6bd4e36578d49e08c773d546cd132e1e6fd789b1b7d65190a4156afabc7a0b42b9890fd42b6a798f9e9112abaf7698fe904fd4dc48c16432a56b1c1c6')

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

