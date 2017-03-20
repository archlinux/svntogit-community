# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-pingpong
_commit=88c7fed
pkgver=20170314.88c7fed
pkgrel=1
pkgdesc="Ping-pong screensaver for Kodi"
arch=('i686' 'x86_64')
url='github.com/notspiff/screensaver.pingpong'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname::git://github.com/notspiff/screensaver.pingpong.git#commit=$_commit")
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

