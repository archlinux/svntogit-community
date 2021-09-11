# Maintainer: Brad Fanella <cesura@archlinux.org>
# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-themes
pkgver=3.22.23
pkgrel=1
pkgdesc="Default themes for the MATE desktop"
url="http://mate-desktop.org"
arch=('any')
license=('GPL')
makedepends=('gtk2' 'intltool')
optdepends=('gtk-engines: for gtk2 themes'
            'gtk-engine-murrine: for gtk2 themes'
            'mate-icon-theme: default icon theme')
options=('!emptydirs')
groups=('mate')
source=("https://pub.mate-desktop.org/releases/themes/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha256sums=('61e5ad626c9841f5763c908f1769139b2a812687b98f6b330afee4da18fb6fab')

build() {
    	cd "${pkgname}-${pkgver}"
    	./configure \
        	--prefix=/usr
    	make
}

package() {
    	cd "${pkgname}-${pkgver}"
    	make DESTDIR="${pkgdir}" install
}
