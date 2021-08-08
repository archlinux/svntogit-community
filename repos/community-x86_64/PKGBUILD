# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-utils
pkgver=1.26.0
pkgrel=1
pkgdesc="Common MATE utilities for viewing disk usage, logs and fonts, taking screenshots, managing dictionaries and searching files"
url="http://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('mate-desktop' 'gettext' 'libcanberra' 'libgtop' 'libsm' 'udisks2')
makedepends=('inkscape' 'itstool' 'mate-panel' 'python')
optdepends=('mate-panel: Look up words in dictionaries from the panel')
groups=('mate-extra')
conflicts=('mate-utils-gtk3')
replaces=('mate-utils-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('7ca56ab242e8efaa64f93ffb84f6e4bf8d4d0df01e20b3b6ef8956ce3192782e')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${_pkgbase} \
        	--sysconfdir=/etc \
        	--disable-maintainer-flags

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
