# $Id$
# Maintainer: Kyle Keen <keenerd@gmail.com>
pkgname=pacmatic
pkgver=20120121
pkgrel=1
pkgdesc="A pacman wrapper to avoid bricking your system and such other surprises."
arch=('any')
url="http://kmkeen.com/pacmatic/"
license=('GPL')
depends=('pacman' 'bash' 'wget' 'pacman-contrib' 'expac')
makedepends=()
optdepends=('vim: for vimdiff')
source=(http://kmkeen.com/pacmatic/$pkgname-$pkgver.tar.gz)
md5sums=('d1e225b855bebfe6e7f031af1a392e14')

package() {
  cd "$srcdir/$pkgname"
  install -D -m 0755 $pkgname   "$pkgdir/usr/bin/$pkgname"
  install -D -m 0644 $pkgname.1 "$pkgdir/usr/share/man/man1/$pkgname.1"
}

