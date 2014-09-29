# Maintainer : Martin Wimpress <code@flexion.org>

pkgname=mate-system-tools
pkgver=1.8.1
pkgrel=1
pkgdesc="Suite of tools for MATE to simplify configuring workstations."
url="http://mate-desktop.org/"
arch=('i686' 'x86_64')
license=('GPL')
depends=('dconf' 'liboobs' 'mate-polkit')
makedepends=('mate-common' 'perl-xml-parser' 'yelp-tools')
optdepends=('yelp: for reading MATE help documents')
groups=('mate-extra')
source=("http://pub.mate-desktop.org/releases/1.8/${pkgname}-${pkgver}.tar.xz")
sha1sums=('99b69facd58e58c9ca668703fcfa353d10bad46d')
install=${pkgname}.install

build() {
    cd "${srcdir}/${pkgname}-${pkgver}"
    ./configure \
        --prefix=/usr \
        --sysconfdir=/etc \
        --disable-caja \
        --disable-network \
        --disable-services \
        --disable-shares \
        --disable-time
    make
}

package() {
    cd "${srcdir}/${pkgname}-${pkgver}"
    make DESTDIR="${pkgdir}" install
}
