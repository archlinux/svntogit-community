# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-applets
pkgver=1.26.1
pkgrel=1
pkgdesc="Applets for MATE panel"
arch=('x86_64')
url="https://mate-desktop.org"
license=('GPL')
depends=('cpupower' 'gtksourceview3' 'libgtop' 'libnotify' 'mate-panel' 'polkit' 'upower' 'wireless_tools')
makedepends=('intltool' 'itstool' 'gucharmap' 'yelp-tools')
optdepends=('fortune-mod: for displaying fortune cookies in the Wanda the Fish applet' 'gucharmap: character picker applet')
groups=('mate-extra')
conflicts=('mate-applets-gtk3' 'mate-netspeed' 'mate-netspeed-gtk3')
replaces=('mate-applets-gtk3' 'mate-netspeed' 'mate-netspeed-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('3ab8f61db376dc333ce4c18722c63a07fab3e8e1272b7e0e097ad4597b17c2c2')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--sysconfdir=/etc \
        	--libexecdir=/usr/lib/${pkgname} \
        	--with-dbus-sys="/usr/share/dbus-1/system.d" \
        	--enable-polkit \
        	--enable-ipv6
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
