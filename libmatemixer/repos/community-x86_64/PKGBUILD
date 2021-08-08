# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=libmatemixer
pkgver=1.26.0
pkgrel=1
pkgdesc="Mixer library for MATE Desktop"
url="https://mate-desktop.org"
arch=('x86_64')
license=('LGPL')
depends=('glib2' 'gettext' 'libpulse' 'alsa-lib')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('9a9bcc605b27e9c5c91a28eb7cb79831e6d6fbf6339f5e5c18d524f3ee259ff1')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--sysconfdir=/etc \
        	--localstatedir=/var

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
