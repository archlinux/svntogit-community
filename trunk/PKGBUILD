# Maintainer: Brad Fanella <cesura@archlinux.org
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=libmateweather
pkgver=1.26.0
pkgrel=1
pkgdesc="Provides access to weather information from the Internet."
url="https://mate-desktop.org"
arch=('x86_64')
license=('LGPL')
depends=('gtk3' 'libsoup' 'gettext')
conflicts=('libmateweather-gtk3')
replaces=('libmateweather-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('a7fd9713099c88826fb67249771cd0cdb92ee9d4784068b1a165840b84607b15')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--sysconfdir=/etc \
        	--localstatedir=/var \
        	--disable-python \
        	--enable-locations-compression

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
