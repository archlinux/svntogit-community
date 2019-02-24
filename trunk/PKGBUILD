# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
epoch=1
pkgver=2.0.3
pkgrel=9
pkgdesc="Spectrum visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.spectrum/archive/v$pkgver.tar.gz")
sha512sums=('ed4a67a9bd1b02bb5d33791bf1953075d993075ec473ac858e9154c867b51ed2ffc8edbffe49344193a28964a48ad945d5376f23fc983ba2d8f1247d26ef298e')

build() {
    cd "visualization.spectrum-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.spectrum-$pkgver"
    make DESTDIR="$pkgdir/" install
}

