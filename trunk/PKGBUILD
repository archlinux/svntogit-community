# Maintainer: Kyle Keen <keenerd@gmail.com>
pkgname=zeromq
pkgver=2.0.10
pkgrel=1
pkgdesc="Fast messaging system built on sockets, C and C++ bindings.  aka 0MQ, ZMQ."
arch=('i686' 'x86_64')
url="http://www.zeromq.org"
license=('LGPL')
depends=('gcc-libs' 'util-linux-ng')
makedepends=()
source=(http://www.zeromq.org/local--files/area:download/$pkgname-$pkgver.tar.gz)
md5sums=('ab794a174210b9e8096a4efd1d1a4d42')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  ./configure prefix="$pkgdir/usr"
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make install
}

