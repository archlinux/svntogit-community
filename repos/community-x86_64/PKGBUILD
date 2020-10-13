# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Maciej Sieczka <msieczka at sieczka dot org>
# Contributor: Michael <mbostwick89@gmail.com>

pkgname=laszip2
pkgver=2.2.0
pkgrel=1
pkgdesc="ASPRS LAS lossless compression library — version 2"
arch=(x86_64)
url="https://laszip.org"
license=(LGPL)
depends=(gcc-libs)
source=(https://download.osgeo.org/laszip/${pkgname%2}-src-${pkgver}.tar.bz2)
sha512sums=('da523243b93296e308eff9121adf9c2a917fc934b21a92a64d192aaa5a1dfbfededc347f5d5ce7b51ea7a5eb5972dc0a5724d50bef26406b359a85c578c60ef8')

build() {
  cd ${pkgname%2}-src-${pkgver}
  ./configure --prefix=/usr --libdir=/usr/lib/${pkgname} --includedir=/usr/include/${pkgname}
  make
}

package() {
  cd ${pkgname%2}-src-${pkgver}
  make DESTDIR="${pkgdir}" install
  rm -r "${pkgdir}"/usr/bin
}
