# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-netbook
pkgver=1.26.0
pkgrel=1
pkgdesc="A simple window management tool"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('libfakekey' 'mate-panel' 'gettext')
groups=('mate-extra')
conflicts=('mate-netbook-gtk3')
replaces=('mate-netbook-gtk3')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('e3bf1b6d9fb266600db408fd9ce97d4a4d3b29586853d4ea46547b6793f1ed89')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexec=/usr/lib/${pkgname} \
        	--sysconfdir=/etc
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
