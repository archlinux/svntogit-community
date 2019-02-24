# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-projectm
epoch=1
pkgver=2.1.0
pkgrel=7
pkgdesc="ProjectM visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.projectm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'projectm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.projectm/archive/v$pkgver.tar.gz"
)
sha512sums=('74924f524d8e4d5c108cf23ae52d034404db9d1d5f63866cda920f552de93f524c6bd7eaff894295c2dae779be11dc17808540f22ad5f2536ec90166d2a95cec')

build() {
    cd "visualization.projectm-$pkgver"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "visualization.projectm-$pkgver"
    make DESTDIR="$pkgdir/" install
}

