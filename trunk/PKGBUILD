# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-biogenesis
_commit=1243d28
pkgver=20170314.1243d28
pkgrel=1
pkgdesc="BioGenesis screensaver for Kodi"
arch=('i686' 'x86_64')
url='https://github.com/notspiff/screensaver.biogenesis'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname::git://github.com/notspiff/screensaver.biogenesis.git#commit=$_commit")
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

