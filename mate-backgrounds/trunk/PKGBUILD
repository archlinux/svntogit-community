# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-backgrounds
pkgver=1.26.0
pkgrel=1
pkgdesc="Background images and data for MATE"
url="https://mate-desktop.org"
arch=('any')
license=('GPL')
groups=('mate')
depends=('gettext')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('0dc9127224ae1573301cfa0aaa6c6262827072d2bf6e5c67c9e1aae19f85e90c')

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
