# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Sébastien Piccand <sebcactus gmail com>

pkgname=tclap
pkgver=1.2.5
pkgrel=1
pkgdesc="Small, flexible library that provides a simple interface for defining and accessing command line arguments"
arch=(any)
url="http://tclap.sourceforge.net/"
license=(MIT)
source=(https://downloads.sourceforge.net/sourceforge/${pkgname}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('bb649f76dae35e8d0dcba4b52acfd4e062d787e6a81b43f7a4b01275153165a6')

build() {
  cd ${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}

package() {
  cd ${pkgname}-${pkgver}
  make DESTDIR="${pkgdir}" install
  install -Dm644 COPYING -t "${pkgdir}"/usr/share/licenses/${pkgname}/
  # Do not package docs, 97% in size
  rm -r "${pkgdir}"/usr/share/doc/
}
