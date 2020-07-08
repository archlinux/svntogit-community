# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Federico Cinelli <cinelli@aur.archlinux.org>
# Contributor: Bob Finch <w9ya@arrl.net>

pkgname=shapelib
pkgver=1.5.0
pkgrel=3
pkgdesc='Simple C API for reading and writing ESRI Shapefiles'
arch=('x86_64')
url='http://shapelib.maptools.org/'
license=('LGPL')
depends=('gcc-libs')
source=(https://download.osgeo.org/$pkgname/$pkgname-$pkgver.tar.gz)
sha256sums=('1fc0a480982caef9e7b9423070b47750ba34cd0ba82668f2e638fab1d07adae1')

build() {
  cd $pkgname-$pkgver

  ./configure --prefix=/usr
  make
}

package() {
  cd $pkgname-$pkgver

  make DESTDIR="${pkgdir}" install
}
