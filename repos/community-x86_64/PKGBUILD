# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-media
pkgver=1.26.0
pkgrel=1
url="https://mate-desktop.org"
pkgdesc="MATE Media Tools"
arch=('x86_64')
license=('GPL')
depends=('libcanberra' 'libmatemixer' 'mate-desktop' 'mate-panel' 'gettext')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
groups=('mate-extra')
conflicts=('mate-media-gtk3')
replaces=('mate-media-gtk3')
sha256sums=('8b731b203fd8219ccc2f2ced40e4301823a17f7940acf3cec72b4494a3fe3c3a')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
       		 --sysconfdir=/etc \
        	--libexecdir=/usr/lib/${pkgname} \
        	--localstatedir=/var
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
