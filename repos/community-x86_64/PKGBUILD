# Maintainer: Daniel Micay <danielmicay@gmail.com>
# Contributor: Nezmer <me at nezmer.info>
pkgname=whowatch
pkgver=1.8.5
pkgrel=1
pkgdesc='Displays information about the users currently logged on to the machine in real time'
arch=(i686  x86_64)
url="http://wizard.ae.krakow.pl/~mike/#whowatch"
license=('GPL2')
depends=(ncurses)
source=(http://wizard.ae.krakow.pl/~mike/download/$pkgname-$pkgver.tar.gz)
md5sums=('8304e8907c7d9e585beda9bec9a9c5fb')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  ./configure --prefix=/usr
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make bindir="$pkgdir/usr/bin" mandir="$pkgdir/usr/share/man" install
}
