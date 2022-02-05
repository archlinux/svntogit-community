# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Brian Galey <bkgaley at gmail dot com>
# Contributor: Bruno Gola <brunogola at gmail dot com>

pkgname=libfreexl
pkgver=1.0.6
pkgrel=2
pkgdesc="Library to extract valid data from within an Excel (.xls) spreadsheet"
arch=('x86_64')
url="https://www.gaia-gis.it/fossil/freexl/index"
license=('MPL' 'GPL' 'LGPL')
depends=('glibc')
source=(https://www.gaia-gis.it/gaia-sins/${pkgname/lib/}-$pkgver.tar.gz)
sha256sums=('3de8b57a3d130cb2881ea52d3aa9ce1feedb1b57b7daa4eb37f751404f90fc22')

build() {
  cd "${srcdir}"/${pkgname/lib/}-$pkgver

  ./configure --prefix=/usr
  make
}

package() {
  cd "${srcdir}"/${pkgname/lib/}-$pkgver

  make DESTDIR="${pkgdir}" install
}
