# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
epoch=1
pkgver=2.0.4
_codename=Leia
pkgrel=11
pkgdesc="Spectrum visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.spectrum/archive/v$pkgver-$_codename.tar.gz")
sha512sums=('69574ae8d3a22fd9cfffb80fff27972fcc76efef217d38d3fe7f66c5dad1cecf3c34438ef06c06de364aec44bb676837bce7af13bb279d16cfb8c35ca5023198')

build() {
    cd "visualization.spectrum-$pkgver-$_codename"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.spectrum-$pkgver-$_codename"
    make DESTDIR="$pkgdir/" install
}

