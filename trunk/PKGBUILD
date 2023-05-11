# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=engrampa
pkgver=1.26.1
pkgrel=1
pkgdesc="Archive manipulator for MATE"
url="https://mate-desktop.org"
arch=('x86_64')
license=('GPL')
depends=('gtk3' 'gzip' 'gettext' 'libarchive' 'tar' 'unzip' 'zip')
makedepends=('caja' 'itstool' 'python')
optdepends=('caja: Caja support'
            'p7zip: 7Z and ARJ archive support'
            'unace: ACE archive support'
            'unrar: RAR archive support'
            'brotli: Brotli compression support'
            'rpm-tools: RPM support'
            'cpio: RPM support')
groups=('mate-extra')
conflicts=("engrampa-gtk3")
replaces=("engrampa-gtk3")
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('f0224107a7a4e9ea6309c9e78aa5faac802c4cf72a49ac283aa9e7ae1e8a6c4a')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr \
        	--libexecdir=/usr/lib/${pkgname} \
        	--disable-packagekit

    	#https://bugzilla.gnome.org/show_bug.cgi?id=656231
    	sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool

    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
