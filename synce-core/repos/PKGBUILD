# Maintainer: Jan Was <janek.jan@gmail.com>

pkgname=synce-core
pkgver=0.17
pkgrel=1
pkgdesc="provide a means of communication with a Windows CE device - libraries"
arch=('i686' 'x86_64')
url="http://synce.sourceforge.net/"
license=('GPL')
depends=('dbus-glib')
makedepends=('dhclient')
provides=('synce-libsynce' 'synce-librapi')
replaces=('synce-libsynce' 'synce-librapi')
conflicts=('synce-libsynce' 'synce-librapi')
options=('!libtool')
source=(http://downloads.sourceforge.net/sourceforge/synce/SynCE/synce-core/synce-core-$pkgver.tar.gz)
md5sums=('ee0b9369b6fea5e2d1b970503dd7cb0e')

build() {
  cd $srcdir/$pkgname-$pkgver
  PYTHON=/usr/bin/python2 ./configure --prefix=/usr --enable-odccm-support --enable-udev-support --enable-bluetooth-support
  make
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make DESTDIR=$pkgdir install
}
