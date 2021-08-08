# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=libmatekbd
pkgver=1.26.0
pkgrel=1
pkgdesc="MATE keyboard library"
url="https://mate-desktop.org"
arch=('x86_64')
license=('LGPL')
depends=('gtk3' 'gettext' 'libxklavier') 
makedepends=('python')
conflicts=('libmatekbd-gtk3')
replaces=('libmatekbd-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('220ee8cab0cbc5f42ca6b621bcd009b0b736507945a2aedbffe2235fa1d811ad')

build() {
    	cd "$pkgname-$pkgver"
    	./configure \
        	--prefix=/usr 

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package_libmatekbd() {
	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
