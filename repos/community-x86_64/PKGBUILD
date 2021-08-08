# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-menus
pkgver=1.26.0
pkgrel=1
pkgdesc="MATE menu specifications"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL' 'LGPL')
depends=('glib2')
makedepends=('gobject-introspection')
groups=('mate')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('0309964abd813053368ac4fc446898d27cdb019e894e78cea75751a68871ffe4')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--sysconfdir=/etc \
        	--localstatedir=/var \
        	--enable-python

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
