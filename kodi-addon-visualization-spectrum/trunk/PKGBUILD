# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
epoch=1
pkgver=1.1.1
pkgrel=1
pkgdesc="Spectrum visualizer for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.spectrum/archive/v$pkgver.tar.gz")
sha512sums=('7288f6d383a34415cb147c5263a20d79a4ee399ef85bdef86f115667967d4a71340dce911f8e7f3ff34a9dd58cd3784b5f97595231c5df6df3e813f16d09258c')

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

