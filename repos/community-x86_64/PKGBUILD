# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-power-manager
pkgver=1.26.0
pkgrel=1
pkgdesc="Power management tool for the MATE desktop"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('dbus-glib' 'gettext' 'libcanberra' 'libnotify' 'upower' 'polkit' 'libsecret')
makedepends=('itstool' 'mate-panel' 'python')
optdepends=('mate-panel: Set brightness and inhibit power management from the panel')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
groups=('mate-extra')
sha256sums=('26b603ccf077366414a41e91ca6aa4c4c227a8e9fb6925a8ec5ca147c4e67b79')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${pkgname} \
        	--sysconfdir=/etc \
        	--localstatedir=/var \
        	--sbindir=/usr/bin \
        	--enable-applets \
        	--disable-strict \
        	--without-keyring
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
