# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
epoch=1
pkgver=3.0.3
_codename=Leia
pkgrel=1
pkgdesc="Spectrum visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'glm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.spectrum/archive/$pkgver-$_codename.tar.gz")
sha512sums=('8c6f111100ae155fc8486dba269d184d65a00235643ed10e77cbe1b5442e466143039fdc1faef17af6545817fd721a7057b09937c91dde1f1b2ceee74f87a935')

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

