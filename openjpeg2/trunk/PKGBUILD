pkgname=openjpeg2
pkgver=2.0.0
pkgrel=1
pkgdesc="An open source JPEG 2000 codec, version ${pkgver}"
arch=(i686 x86_64)
license=('BSD')
url="http://www.openjpeg.org"
makedepends=('cmake')
depends=('zlib')
options=('!libtool')
source=(http://openjpeg.googlecode.com/files/openjpeg-${pkgver}.tar.gz)
sha1sums=('0af78ab2283b43421458f80373422d8029a9f7a7')

build() {
  cd "${srcdir}/openjpeg-${pkgver}"
  cmake -DCMAKE_INSTALL_PREFIX=/usr .
  make
}

package() {
  cd "${srcdir}/openjpeg-${pkgver}"
  make DESTDIR="${pkgdir}" install
}
