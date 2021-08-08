# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-user-share
pkgver=1.26.0
pkgrel=1
pkgdesc="User level public file sharing via WebDAV for MATE"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('gtk3' 'mod_dnssd' 'gettext')
makedepends=('caja' 'dbus-glib' 'itstool' 'libcanberra' 'libnotify')
optdepends=('caja: File sharing extension')
groups=('mate-extra')
conflicts=('mate-user-share-gtk3')
replaces=('mate-user-share-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('f04e01d7631951c89860e8bb3e20a3b49b9c96e49712f2f4a1f7f3c2315900f2')

build() {
    	cd "${pkgname}-${pkgver}"
    	PYTHON=/usr/bin/python2 ./configure \
        	--prefix=/usr \
        	--libexec=/usr/lib/${pkgname} \
        	--sysconfdir=/etc \
        	--disable-bluetooth

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make  DESTDIR="${pkgdir}" install
}
