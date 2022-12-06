# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-polkit
pkgver=1.26.1
pkgrel=1
pkgdesc="PolicyKit integration for the MATE desktop"
url="https://mate-desktop.org"
arch=('x86_64')
license=('LGPL')
groups=('mate')
depends=('gtk3' 'polkit' 'gettext')
makedepends=('accountsservice' 'gobject-introspection')
conflicts=('mate-polkit-gtk3')
replaces=('mate-polkit-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('f5b7b0b5dfc53302c40403245998eb9121af3f50e71666a09ab73bb254520357')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${pkgname} \
        	--sysconfdir=/etc \
        	--localstatedir=/var \
        	--enable-introspection

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
