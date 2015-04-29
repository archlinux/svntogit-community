# Maintainer: Niels Martignène <niels.martignene@gmail.com>
# Contributor: Nicolas Avrutin <nicolasavru@gmail.com>
# Contributor: Emmanuel Gil Peyrot <linkmauve@linkmauve.fr>

pkgname=hidapi
pkgver=0.8.0rc1
_hidapiver=0.8.0-rc1
pkgrel=2
pkgdesc="Simple library for communicating with USB and Bluetooth HID devices"
arch=(i686 x86_64)
url="http://www.signal11.us/oss/hidapi/"
license=('GPL3' 'BSD' 'custom')
depends=('libusb')
conflicts=('hidapi-git')
source=("https://github.com/signal11/hidapi/archive/hidapi-${_hidapiver}.tar.gz")
md5sums=('069f9dd746edc37b6b6d0e3656f47199')

build() {
  cd "${srcdir}/hidapi-hidapi-${_hidapiver}"

  ./bootstrap
  ./configure --prefix=/usr
  make
}

package() {
  cd "${srcdir}/hidapi-hidapi-${_hidapiver}"

  make DESTDIR="${pkgdir}/" install

  mkdir -p "${pkgdir}/usr/share/licenses/${pkgname}"
  rm -f "${pkgdir}/usr/share/doc/hidapi/"LICENSE*
  install -m644 LICENSE.txt LICENSE-bsd.txt LICENSE-orig.txt "${pkgdir}/usr/share/licenses/${pkgname}/"
}
