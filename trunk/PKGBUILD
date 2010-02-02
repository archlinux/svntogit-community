# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=macchanger
pkgver=1.5.0
pkgrel=3
pkgdesc="A small utility to change you NIC's MAC address"
arch=('i686' 'x86_64')
url="http://ftp.gnu.org/gnu/macchanger"
license=('GPL')
source=(http://ftp.gnu.org/gnu/macchanger/${pkgname}-${pkgver}.tar.gz)
md5sums=('79b7cdaeca3d8ebafa764c4b0dd03ab7')

build() {
	cd ${srcdir}/${pkgname}-${pkgver}
	./configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/man
	make || return 1
}

package() {
	cd ${srcdir}/${pkgname}-${pkgver}

	make DESTDIR=${pkgdir} install || return 1
}
