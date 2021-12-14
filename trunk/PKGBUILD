# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Allan McRae <allan@archlinux.org>
# Contributor: Ben <contrasutra@myrealbox.com>
# Contributor: Lukasz Fidosz <virhilo@gmail.com>

pkgname=menumaker
pkgver=0.99.14
pkgrel=2
pkgdesc="Heuristics-driven menu generator for Deskmenu, FluxBox, IceWM, OpenBox, WindowMaker and XFCE"
arch=('any')
url="http://menumaker.sourceforge.net/"
license=('BSD')
depends=('python')
options=('!makeflags')
source=(https://downloads.sourceforge.net/$pkgname/$pkgname-$pkgver.tar.gz)
sha512sums=('81d44c1917d0fd4cd1c8b7cdd4ce12795fee7cc286959a7fc9dc6f84a096ea850a4348d98b6a7dce153c5d07fdb8b3aaf13f3476a9f34dd56646af3097d406d0')

build() {
  cd "${srcdir}"/${pkgname}-${pkgver}

  ./configure --prefix=/usr --infodir=/usr/share/info
  make
}

package() {
  cd "${srcdir}"/${pkgname}-${pkgver}

  make DESTDIR="${pkgdir}" install
  rm -rf "${pkgdir}"/usr/share/info

#license
  install -Dm644 COPYING "${pkgdir}"/usr/share/licenses/${pkgname}/license
}
