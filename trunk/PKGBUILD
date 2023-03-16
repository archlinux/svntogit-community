# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-desktop
pkgver=1.26.1
pkgrel=1
pkgdesc="Library with common API for various MATE modules"
url="http://mate-desktop.org"
arch=('x86_64')
license=('GPL' 'LGPL')
depends=('gtk3' 'startup-notification' 'iso-codes')
makedepends=('gobject-introspection' 'intltool')
groups=('mate')
conflicts=('mate-desktop-gtk3' 'mate-desktop-schemas')
replaces=('mate-desktop-gtk3' 'mate-desktop-schemas')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('12d1668a27ac1abd60935381d3f39821bb808467a7b8acf9ef45885d7c80a211')

build() {
	cd "$pkgname-$pkgver"
    	./configure \
        	--prefix=/usr \
        	--disable-schemas-compile

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "$pkgname-$pkgver"

    	make DESTDIR="${pkgdir}" install
}
