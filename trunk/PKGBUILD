# Maintainer: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Eric Johnson <eric@coding-zone.com>

pkgname=aspell-it
pkgver=2.4_20070901
pkgrel=1
pkgdesc="Italian dictionary for aspell"
arch=('any')
url="http://aspell.net/"
license=('GPL')
depends=('aspell')
source=("https://sourceforge.net/projects/linguistico/files/Dizionario%20italiano%20per%20Aspell/${pkgver/_/-}-0/aspell6-it-${pkgver/_/-}-0.tar.bz2")
sha512sums=('6a5014880e51103e70d57a6b01e2d4bb5d51ae939f72ee9270b46891804203399c817dd73c3a0b91c004744a4e66a1a5b402d19be0a53db952152cdd3c1741e9')

build() {
  cd "${srcdir}/aspell6-it-${pkgver/_/-}-0"

  ./configure
  make
}

package() {
  cd "${srcdir}/aspell6-it-${pkgver/_/-}-0"

  make DESTDIR="${pkgdir}" install
}
