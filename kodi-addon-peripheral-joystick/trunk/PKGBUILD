# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-peripheral-joystick
pkgver=1.4.9
_codename=Leia
pkgrel=2
pkgdesc="Joystick support for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/peripheral.joystick'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-peripheral')
depends=('kodi-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/peripheral.joystick/archive/$pkgver-$_codename.tar.gz")
sha512sums=('6d5d8e5922c7b9c38a55372da585366331f550864ee7d95369bb8b32897250b38d4cbb0e2f5fc7eb91aea34f09f6f33a62b148f731f422ac1b6ead9b2eac4ae5')

build() {
    cd "peripheral.joystick-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "peripheral.joystick-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

