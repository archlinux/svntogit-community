# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Marco Maso <demind@gmail.com>
# Contributor: Adrian Benson <adrian_benson@yahoo.co.nz>

pkgname=qrupdate
pkgver=1.1.2
pkgrel=3
pkgdesc="Fortran library for fast updates of QR and Cholesky decompositions"
url="http://sourceforge.net/projects/qrupdate"
makedepends=(gcc-fortran)
depends=(lapack)
arch=(x86_64)
license=(GPL3)
source=( http://downloads.sourceforge.net/project/qrupdate/qrupdate/1.2/$pkgname-$pkgver.tar.gz)
sha256sums=('e2a1c711dc8ebc418e21195833814cb2f84b878b90a2774365f0166402308e08')

build() {
  cd $pkgname-$pkgver
  make PREFIX=/usr solib
}

check() {
  cd $pkgname-$pkgver
  make test
}

package() {
  cd $pkgname-$pkgver
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
