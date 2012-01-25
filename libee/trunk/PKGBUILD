# Maintainer: Brian Knox <taotetek@gmail.com>

pkgname=libee
pkgver=0.3.1
pkgrel=3
pkgdesc="event expression library inspired by CEE"
url="http://www.libee.org/"
arch=('i686' 'x86_64')
license=('LGPL2.1')
depends=('libestr')
makedepends=()
optdepends=()
options=()
source=("http://www.libee.org/files/download/libee-$pkgver.tar.gz")
md5sums=('61403a9a62b984381cf48454664f915e')
build() {
  cd ${srcdir}/${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}
package() {
  cd ${srcdir}/${pkgname}-${pkgver}
  make install DESTDIR=${pkgdir}
}
