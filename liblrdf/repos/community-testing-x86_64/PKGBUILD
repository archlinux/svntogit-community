# Maintainer: David Runge <dave@sleepmap.de>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>

pkgname=liblrdf
pkgver=0.6.1
pkgrel=4
pkgdesc="A library for the manipulation of RDF file in LADSPA plugins"
arch=('x86_64')
url="https://github.com/swh/LRDF"
depends=('raptor')
makedepends=('ladspa')
provides=('liblrdf.so')
license=('GPL2')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/swh/LRDF/archive/v${pkgver}.tar.gz")
sha512sums=('7732813eec704aef984d056de254e4fa049fdd0a7444b6a88f75f012afe9c587cbd1295f027c77361fa42bc097cdce9d9cabdba6b86e99a3c14805d84258df1c')

prepare() {
  mv -v "LRDF-${pkgver}" "${pkgname}-${pkgver}"
  cd "${pkgname}-${pkgver}"
  autoreconf -vfi
}

build() {
  cd "${pkgname}-${pkgver}"
  # raptor.h changed location
  export CXXFLAGS="$(pkg-config --cflags raptor2) ${CXXFLAGS}"
  ./configure --prefix=/usr
  make
}

package() {
  cd "${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
  install -vDm 644 {AUTHORS,ChangeLog,NEWS,README} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
