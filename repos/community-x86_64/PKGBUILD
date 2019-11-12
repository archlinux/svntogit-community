# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Maciej Sieczka <msieczka at sieczka dot org>
# Contributor: Michael <mbostwick89@gmail.com>

pkgname=laszip
pkgver=3.4.3
pkgrel=1
pkgdesc='ASPRS LAS lossless compression library'
arch=('x86_64')
url='https://laszip.org'
license=('LGPL')
makedepends=('cmake')
source=("https://github.com/LASzip/LASzip/releases/download/${pkgver}/laszip-src-${pkgver}.tar.gz")
sha512sums=('52033d4e271a75f77de9f112e034ff080e476c0d117010136088b255323e4542550c0fa4f87d86521959787919ca3c7e49ef8c8975ba8f8239799a4d7f34d53f')

build() {
  cd "${srcdir}/${pkgname}-src-${pkgver}"

  mkdir build && cd build
  cmake -DCMAKE_INSTALL_PREFIX=/usr ..
  make
}

package() {
  cd "${srcdir}/${pkgname}-src-${pkgver}/build"
  make DESTDIR="$pkgdir" install
}
