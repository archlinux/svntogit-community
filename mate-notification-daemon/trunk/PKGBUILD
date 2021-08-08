# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-notification-daemon
pkgver=1.26.0
pkgrel=1
provides=('notification-daemon')
pkgdesc="Notification daemon for MATE"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
groups=('mate')
depends=('libcanberra' 'libwnck3' 'libnotify' 'gettext' 'mate-panel')
makedepends=('python')
conflicts=('mate-notification-daemon-gtk3')
replaces=('mate-notification-daemon-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('b23c6581f8f5916d6a16584edd91c2e4b6d0db7dd8e1eec5dd360acf2834b9ba')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${pkgname}

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
