# $Id: PKGBUILD 35989 2010-12-25 03:22:46Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Alexander Suhoverhov <cy at ngs dot ru>
pkgname=xonotic-data
pkgver=0.5.0
pkgrel=1
pkgdesc="A free, fast-paced crossplatform first-person shooter (data files)"
arch=('any')
url="http://xonotic.org"
license=('GPL')
depends=()
makedepends=('unzip')
source=("http://dl.xonotic.org/xonotic-${pkgver}.zip")
md5sums=('cdadb384ccf9cad926bb377312832c2f')

build() {
  cd $srcdir/Xonotic/source/darkplaces
}

package() {
  cd $srcdir/Xonotic
  
  # data
  mkdir -p $pkgdir/usr/share/xonotic/
  mv $srcdir/Xonotic/data $pkgdir/usr/share/xonotic/
}
# vim: ts=2:sw=2 et:
