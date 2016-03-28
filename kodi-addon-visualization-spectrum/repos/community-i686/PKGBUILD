# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-spectrum
_commit=9dbe53a
pkgver=20151213.9dbe53a
pkgrel=1
pkgdesc="Spectrum visualizer for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/visualization.spectrum'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi')
makedepends=('git' 'cmake')
source=("$pkgname::git://github.com/notspiff/visualization.spectrum.git#commit=$_commit")
sha256sums=('SKIP')

pkgver() {
	cd "$pkgname"
	git log -1 --date=short --format="%cd.%h" | tr -d '-'
}

build() {
	cd "$pkgname"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
	cd "$pkgname"
	make DESTDIR="$pkgdir/" install
}

