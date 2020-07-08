# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-waveform
epoch=1
pkgver=3.1.1
_codename=Leia
pkgrel=9
pkgdesc="Waveform visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.waveform'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'glu' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.waveform/archive/$pkgver-$_codename.tar.gz")
sha512sums=('0ed887c892b20fc4e162e9d7317d20ceb1cfce2db2cfcfa948995349ae8c97c33520202052d80c01d1122c50fac0772f18245aa40b4b7b7b55917fa533b65cd9')

build() {
    cd "visualization.waveform-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.waveform-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

