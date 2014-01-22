# Maintainer: Denis Wernert <deniswernert@gmail.com>

pkgname=liblogging
pkgver=0.7.1
pkgrel=1
pkgdesc="easy to use, portable, open source library for system logging"
url="http://www.liblogging.org/"
arch=('i686' 'x86_64')
license=('GPL')
options=('strip' 'zipman' '!libtool')
source=("http://download.rsyslog.com/$pkgname/$pkgname-$pkgver.tar.gz")
md5sums=('17a0de3f2a403f6baafcf608d8728690')

build() {
  cd ${srcdir}/${pkgname}-${pkgver}
  ./configure --prefix=/usr || return 1
  make || return 1
}

package() {
  cd ${srcdir}/${pkgname}-${pkgver}
  make install DESTDIR=${pkgdir} || return 1
}
