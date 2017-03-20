# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pyro
_commit=2d15f72
pkgver=20170314.2d15f72
pkgrel=1
pkgdesc="Pyro screensaver for Kodi"
arch=('i686' 'x86_64')
url='github.com/notspiff/screensaver.pyro'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname::git://github.com/notspiff/screensaver.pyro.git#commit=$_commit")
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

