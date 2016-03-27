# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-asteroids
_commit=c7ae05f
pkgver=20150921.c7ae05f
pkgrel=1
pkgdesc="Asteroids screensaver for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/screensaver.asteroids'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake')
source=("$pkgname::git://github.com/notspiff/screensaver.asteroids.git#commit=$_commit")
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

