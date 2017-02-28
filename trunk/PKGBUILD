# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-visualization-projectm
_commit=0e897a4
pkgver=20170221.0e897a4
pkgrel=1
pkgdesc="ProjectM visualizer for Kodi"
arch=('i686' 'x86_64')
url='github.com/notspiff/visualization.projectm'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-visualization')
depends=('kodi' 'p8-platform' 'projectm')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname::git://github.com/notspiff/visualization.projectm.git#commit=$_commit")
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

