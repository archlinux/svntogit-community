# Maintainer:
# Contributor: Simo Leone <simo@archlinux.org>
# Contributor: Juan Pablo León <jp_leon@gmx.net>

pkgname=aspell-es
pkgver=1.11
pkgrel=9
pkgdesc="Spanish dictionary for aspell"
arch=('x86_64')
url="http://aspell.net/"
license=('GPL')
depends=('aspell')
source=("https://ftp.gnu.org/gnu/aspell/dict/es/aspell6-es-$pkgver-2.tar.bz2")
md5sums=('8406336a89c64e47e96f4153d0af70c4')
sha256sums=('ad367fa1e7069c72eb7ae37e4d39c30a44d32a6aa73cedccbd0d06a69018afcc')

build() {
  cd aspell6-es-$pkgver-2
  ./configure
  make
}

package() {
  cd aspell6-es-$pkgver-2
  make DESTDIR="$pkgdir" install
}
