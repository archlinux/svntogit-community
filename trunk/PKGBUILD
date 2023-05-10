# Maintainer: Jaroslav Lichtblau <svetlemodry@archlinux.org>
# Contributor: Eric Bélanger <eric@archlinux.org>

pkgname=pysolfc-cardsets
pkgver=2.2
pkgrel=1
pkgdesc="A collection of cardsets adapted for use with PySolFC"
arch=('any')
url="http://pysolfc.sourceforge.net/"
license=('GPL3')
source=(https://downloads.sourceforge.net/pysolfc/PySolFC-Cardsets-$pkgver.tar.bz2)
sha256sums=('53be2038cf201403a65266bf4b9ad8e3b8192bb253aba6af36964a71ea6f7755')

package() {
  cd "${srcdir}"/PySolFC-Cardsets-$pkgver

  install -d "${pkgdir}"/usr/share/PySolFC
  cp -r * "${pkgdir}"/usr/share/PySolFC
}
