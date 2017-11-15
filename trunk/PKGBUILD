# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-projectm
epoch=1
pkgver=1.2.1
pkgrel=1
pkgdesc="ProjectM visualizer for Kodi"
arch=('x86_64')
url='github.com/notspiff/visualization.projectm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform' 'projectm')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/visualization.projectm/archive/v$pkgver.tar.gz")
sha512sums=('37091b7656c791434c80572d57424bfc7161c0f2b752adffc2c4d837c93d733e104f7b68893544f3efc32c67e607882063c34ecae240754b1c71856d83ba4c2e')

build() {
    cd "visualization.projectm-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "visualization.projectm-$pkgver"
	make DESTDIR="$pkgdir/" install
}

