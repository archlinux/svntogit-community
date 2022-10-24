# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Luca Weiss <luca (at) z3ntu (dot) xyz>
# Contributor: Sam S. <smls75@gmail.com>
# Contributor: Nuno Araujo <nuno.araujo@russo79.com>

pkgname=pmbootstrap
pkgver=1.48.0
pkgrel=1
pkgdesc='Sophisticated chroot/build/flash tool to develop and install postmarketOS'
url='https://gitlab.com/postmarketOS/pmbootstrap'
arch=('any')
license=('GPL3')
depends=('python' 'python-argcomplete')
makedepends=('python-setuptools')
source=("https://gitlab.com/postmarketOS/pmbootstrap/-/archive/$pkgver/pmbootstrap-$pkgver.tar.gz")
sha512sums=('f7bcb2925108438747b535ec76f0f975647e54d123c121e1a69ab26210f1124818bdfa4802bb4a174abf6187c55cab52581b7e00bcf5ab07d8658b423afd69ce')

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1 --skip-build
}

# vim: ts=2 sw=2 et:
