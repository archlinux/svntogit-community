# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-goom
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="GOOM visualizer for Kodi"
arch=('x86_64')
url='github.com/notspiff/visualization.goom'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.goom/archive/v$pkgver.tar.gz")
sha512sums=('d0e7ab3931ad32f16f4b97f3746e2e5ec9ed08ba23184ac880ab4da1c0da16511c6a9e1ea595ccbbac3c7c8f385fa5dced1e554d0a1a8122db4f35223eb66ace')

build() {
    cd "visualization.goom-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.goom-$pkgver"
	make DESTDIR="$pkgdir/" install
}

