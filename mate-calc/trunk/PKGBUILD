# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-calc
pkgver=1.26.0
pkgrel=1
pkgdesc="Calculator for the MATE desktop environment"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('gtk3' 'gettext' 'libmpc')
makedepends=('itstool')
groups=('mate-extra')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('7eb826801dda5d7b070e41d9e831df2ad24459be6c96fe9c0506c21e1374ad55')

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
