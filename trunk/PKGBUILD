# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-waveform
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Waveform visualizer for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/visualization.waveform'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.waveform/archive/v$pkgver.tar.gz")
sha512sums=('243696af3388506a52c46c8e636f5cbe973c916e1b03f24ad58327642721cf1a492fb16a7a0e69cd80732b8b435b009862dffca78dc8974f86cbb092a6aff195')

build() {
    cd "visualization.waveform-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.waveform-$pkgver"
	make DESTDIR="$pkgdir/" install
}

