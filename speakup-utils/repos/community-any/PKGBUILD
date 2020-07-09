# Maintainer: David Runge <dave@sleepmap.de>
# Contributor: Chris Brannon <cmbrannon79@gmail.com>

_name=speakup
pkgname=speakup-utils
pkgver=3.1.6
pkgrel=6
pkgdesc='Tiny utilities for controlling the Speakup screenreader'
arch=('any')
url="http://linux-speakup.org/"
depends=('sh')
license=('GPL2')
source=("ftp://linux-speakup.org/pub/${_name}/${_name}-${pkgver}.tar.bz2")
sha512sums=('d591cddb8bf2e331463d556b19fbce0109a2b353a27aa90b130903ec431630fe7ed65e07cc76a6f42f2960791dc7993bce5d5e0c2d855a8ef1935afc4cdd967d')

package() {
  cd "${_name}-$pkgver"
  install -vDm 755 tools/{speakupconf,talkwith} -t "${pkgdir}/usr/bin/"
  install -vDm 644 man/{speakupconf,talkwith}.1 \
    -t "${pkgdir}/usr/share/man/man1/"
  install -vDm 644 tools/README -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
