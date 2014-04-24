# Maintainer: Andrea Fagiani <andfagiani {at} gmail {dot} com>
# Contributor: Brett Mravec <brett.mravec@gmail.com>

pkgname=libnih
pkgver=1.0.3
pkgrel=1
pkgdesc="Small library for C application development."
arch=(i686 x86_64)
url="https://launchpad.net/libnih"
license=('GPL')
depends=('dbus-core')
makedepends=('expat')
options=(!libtool)
source=(http://launchpad.net/libnih/1.0/${pkgver}/+download/$pkgname-$pkgver.tar.gz)
md5sums=('db7990ce55e01daffe19006524a1ccb0')

build() {
  cd $srcdir/$pkgname-$pkgver

  ./configure --prefix=/usr
  make
  make DESTDIR=$pkgdir/ install

}
