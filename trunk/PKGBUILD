# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-fishbmc
epoch=1
pkgver=4.1.0
pkgrel=1
pkgdesc="Fisch visualizer for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/visualization.fishbmc'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.fishbmc/archive/v$pkgver.tar.gz")

build() {
    cd "visualization.fishbmc-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.fishbmc-$pkgver"
	make DESTDIR="$pkgdir/" install
}

sha512sums=('6107228b8a3f92a047003ef3a34dc57d187d9c6b1f28e2f8d326fd71e7e7b586750c02a3bb9b11cdda322cbdc5d3fe0146c08364029da028fd65d0f3a13a3358')
