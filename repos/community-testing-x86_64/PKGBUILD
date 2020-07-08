# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Michal Karas <largon@largon.net>

pkgname=aspell-cs
pkgver=20040614
pkgrel=10
pkgdesc="Czech dictionary for aspell"
arch=('x86_64')
url="http://aspell.net/"
license=('GPL')
depends=('aspell')
source=(ftp://ftp.gnu.org/gnu/aspell/dict/cs/aspell6-cs-$pkgver-1.tar.bz2)
sha256sums=('01c091f907c2fa4dfa38305c2494bb80009407dfb76ead586ad724ae21913066')

build() {
  cd "${srcdir}"/aspell6-cs-$pkgver-1

  ./configure
  make
}

package() {
  cd "${srcdir}"/aspell6-cs-$pkgver-1

  make DESTDIR="${pkgdir}" install
}
