# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=marco
pkgver=1.26.2
pkgrel=2
pkgdesc="A window manager for MATE"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('libcanberra' 'libgtop' 'mate-desktop' 'zenity' 'libxpresent' 'gettext' 'libxres' 'libsm')
makedepends=('itstool')
groups=('mate')
conflicts=('marco-gtk3')
replaces=('marco-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('12f1a254fe1072f0304884711e089a5682780a011593402ed38de6b9480e07a3')

build() {
	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--sysconfdir=/etc \
        	--localstatedir=/var \
        	--enable-startup-notification

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
