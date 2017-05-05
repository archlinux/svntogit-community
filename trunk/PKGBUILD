# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-rsxs
_commit=579ec13
pkgver=20170429.579ec13
pkgrel=1
pkgdesc="RSXS screensaver add-ons for Kodi"
arch=('i686' 'x86_64')
url='github.com/notspiff/screensavers.rsxs'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake' 'kodi-dev')
source=(
    "$pkgname::git://github.com/notspiff/screensavers.rsxs.git#commit=$_commit"
)
sha256sums=(
    'SKIP'
)

pkgver() {
	cd "$pkgname"
	git log -1 --date=short --format="%cd.%h" | tr -d '-'
}

#prepare() {
    #cd "$pkgname"
#}

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

