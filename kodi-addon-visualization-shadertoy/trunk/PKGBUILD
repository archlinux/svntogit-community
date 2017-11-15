# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-shadertoy
epoch=1
pkgver=1.1.5
pkgrel=1
pkgdesc="Shadertoy visualizer for Kodi"
arch=('x86_64')
url='https://github.com/notspiff/visualization.shadertoy'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.shadertoy/archive/v$pkgver.tar.gz")
sha512sums=('557cc9567707ab53c63537f760b552c4129f45a4c99346acf9d00f8fea5249af1a8af9ea6fc8587e7ab6e24c8a686356e5bacf0a2cb34dcc8b38059c36127e43')

build() {
    cd "visualization.shadertoy-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.shadertoy-$pkgver"
	make DESTDIR="$pkgdir/" install
}

