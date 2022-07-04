# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=caja
pkgver=1.26.1
pkgrel=1
pkgdesc="File manager for the MATE desktop"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('exempi' 'gvfs' 'libexif' 'libsm' 'mate-desktop' 'libnotify')
makedepends=('gobject-introspection' 'intltool')
optdepends=('gstreamer: automatic media playback when mouseover')
groups=('mate')
conflicts=('caja-gtk3')
replaces=('caja-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/$pkgname-$pkgver.tar.xz")
sha256sums=('30fd6e6f00a38200f6e2e898ad7fa797876bb060f1d0341dd2f7393279e14c07')

build() {
	cd "$pkgname-$pkgver"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/$pkgname \
        	--enable-introspection \
        	--disable-update-mimedb

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "$pkgname-$pkgver"
    	make DESTDIR="${pkgdir}" install

    	# Remove D-Bus activation file to avoid conflict with nautilus-desktop
    	rm -r "$pkgdir/usr/share/dbus-1/"
}
