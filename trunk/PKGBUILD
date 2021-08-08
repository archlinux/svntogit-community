# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-common
pkgver=1.26.0
pkgrel=1
pkgdesc="Common development macros for MATE"
arch=('any')
license=('GPL')
depends=('autoconf' 'automake' 'gettext' 'gtk-doc' 'libtool'
         'pkg-config')
url="https://mate-desktop.org"
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('4ec9e308ef7ea87435769976b5bd7e41d612be2357a91bd0fed3557cb1bb9c04')

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
