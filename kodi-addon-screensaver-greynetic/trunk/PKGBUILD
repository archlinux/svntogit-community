# $Id$
# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-addon-screensaver-greynetic
epoch=1
pkgver=1.1.0
pkgrel=1
pkgdesc="Greynetic screensaver for Kodi"
arch=('x86_64')
url='github.com/notspiff/screensaver.greynetic'
license=('GPL')
groups=('kodi-addons' 'kodi-addons-screensaver')
depends=('kodi')
makedepends=('cmake' 'kodi-dev')
source=("$pkgname-$pkgver.tar.gz::https://github.com/notspiff/screensaver.greynetic/archive/v$pkgver.tar.gz")
sha512sums=('ebc35da057f425ab5a4832324f4e26bbd6767aa1aed13177073caab8a099b4a4cbcb6e9c84ae88970eb13401bdf411422588ed9ba83a9d5d9749c3add6e43375')

build() {
    cd "screensaver.greynetic-$pkgver"
	cmake \
		-DCMAKE_INSTALL_PREFIX=/usr \
		-DCMAKE_BUILD_TYPE=Release \
		-DBUILD_SHARED_LIBS=1 \
		-DUSE_LTO=1
	make
}

package() {
    cd "screensaver.greynetic-$pkgver"
	make DESTDIR="$pkgdir/" install
}

