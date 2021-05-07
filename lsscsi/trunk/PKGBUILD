# Maintainer: Sébastien Luttringer
# Contributor: XAVeRY - los dot danielos at gmail dot com

pkgname=lsscsi
pkgver=0.32
pkgrel=1
pkgdesc='A tool that lists devices connected via SCSI and its transports'
arch=('x86_64')
url='http://sg.danny.cz/scsi/lsscsi.html'
license=('GPL')
depends=('sysfsutils')
source=("http://sg.danny.cz/scsi/$pkgname-$pkgver.tgz")
sha256sums=('0a800e9e94dca2ab702d65d72777ae8cae078e3d74d0bcbed64ba0849e8029a1')

build() {
  cd $pkgname-*/
  ./configure --prefix=/usr
  make
}

package() {
  cd $pkgname-*/
  make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
