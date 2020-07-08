# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-projectm
epoch=1
pkgver=2.2.0
pkgrel=16
pkgdesc="ProjectM visualizer for Kodi"
arch=('x86_64')
url='https://github.com/xbmc/visualization.projectm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'projectm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/xbmc/visualization.projectm/archive/v$pkgver.tar.gz"
)
sha512sums=('6b16f6d186d7ab3bcc84ef60a1227f61a6244c2328ba685d606a29dd6b8e08270e58de26498af274970c3e2ad0a41597cd091a30209ad05c88bb8313995ae3a7')

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

