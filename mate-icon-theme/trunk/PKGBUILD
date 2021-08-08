# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-icon-theme
pkgver=1.26.0
pkgrel=1
pkgdesc="MATE icon theme"
url="https://mate-desktop.org"
arch=('any')
license=('LGPL')
options=('!emptydirs')
depends=('gettext')
makedepends=('icon-naming-utils')
groups=('mate')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('41f50436d57f425e54fd9557541be77fb291e03aacd55f7991c042e84a290a5a')

build() {
   	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
