# $Id: PKGBUILD,v 1.2 2007/07/06 07:07:40 tardo Exp $

pkgname=macchanger
pkgver=1.5.0
pkgrel=1
pkgdesc="A small utility to change you NIC's MAC address"
arch=('i686' 'x86_64')
url="http://ftp.gnu.org/gnu/macchanger"
license=('GPL')
source=(http://ftp.gnu.org/gnu/macchanger/$pkgname-$pkgver.tar.gz)
md5sums=('79b7cdaeca3d8ebafa764c4b0dd03ab7')

build() {
  cd $startdir/src/$pkgname-$pkgver
  ./configure --prefix=/usr
  make || return 1
  make DESTDIR=$startdir/pkg install || return 1
}
