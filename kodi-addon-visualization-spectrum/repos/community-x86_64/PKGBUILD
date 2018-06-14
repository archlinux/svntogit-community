# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
epoch=1
pkgver=1.1.4
pkgrel=2
pkgdesc="Spectrum visualizer for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.spectrum/archive/v$pkgver.tar.gz")
sha512sums=('452136882edafa9871208db5efbf214706396c8429e75f71ffd30c9e42b7d08f35a6a302e8cde79bc28533a0c990c2fc371e86675f77cfb341cd8f65833454f9')

build() {
    cd "visualization.spectrum-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.spectrum-$pkgver"
	make DESTDIR="$pkgdir/" install
}

