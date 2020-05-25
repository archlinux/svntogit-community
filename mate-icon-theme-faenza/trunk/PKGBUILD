# Contributor: Martin Wimpress <code@flexion.org>

pkgname=mate-icon-theme-faenza
pkgver=1.20.0
pkgrel=2
pkgdesc="Faenza icon theme for MATE"
url="https://mate-desktop.org"
arch=('any')
license=('GPL')
makedepends=('mate-common')
groups=('mate-extra')
source=("https://pub.mate-desktop.org/releases/${pkgver%.*}/${pkgname}-${pkgver}.tar.xz")
sha1sums=('08f32e19012bc7501ac445b1a6e13f7cba0a113a')

build() {
    cd ${pkgname}-${pkgver}
    ./autogen.sh
    ./configure \
        --prefix=/usr
    make
}

package() {
    cd ${pkgname}-${pkgver}
    make DESTDIR="${pkgdir}" install
}
