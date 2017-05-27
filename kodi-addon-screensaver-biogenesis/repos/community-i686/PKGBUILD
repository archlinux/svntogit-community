# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-biogenesis
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="BioGenesis screensaver for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/screensaver.biogenesis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.biogenesis/archive/v$pkgver.tar.gz")

build() {
    cd "screensaver.biogenesis-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1
    make
}

package() {
    cd "screensaver.biogenesis-$pkgver"
	make DESTDIR="$pkgdir/" install
}

sha512sums=('db970113a44d87ccf44c520d5d6adfc640617ba9fd01f0b0114129d1901b2e853804871d9f5377a0869034b2379663922069545f3a7bd38f98b2d9894013c5ae')
