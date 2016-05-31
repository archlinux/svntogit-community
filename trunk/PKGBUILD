# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-rsxs
_commit=781f76f
pkgver=20160523.781f76f
pkgrel=1
pkgdesc="RSXS screensaver add-ons for Kodi"
arch=('i686' 'x86_64')
url='github.com/notspiff/screensavers.rsxs'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('git' 'cmake')
source=(
    "$pkgname::git://github.com/notspiff/screensavers.rsxs.git#commit=$_commit"
    '0001-fix-gcc5-compile.patch'
)
sha256sums=(
    'SKIP'
    '81608c72969da767f754c41dfbe8e5cf9af9f4f1e91e57c39a0424df58275580'
)

pkgver() {
	cd "$pkgname"
	git log -1 --date=short --format="%cd.%h" | tr -d '-'
}

prepare() {
    cd "$pkgname"
    patch -p1 -i "$srcdir/0001-fix-gcc5-compile.patch"
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

