# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Luca Weiss <luca (at) z3ntu (dot) xyz>
# Contributor: Sam S. <smls75@gmail.com>
# Contributor: Nuno Araujo <nuno.araujo@russo79.com>

pkgname=pmbootstrap
pkgver=1.49.0
pkgrel=1
pkgdesc='Sophisticated chroot/build/flash tool to develop and install postmarketOS'
url='https://gitlab.com/postmarketOS/pmbootstrap'
arch=('any')
license=('GPL3')
depends=('python' 'python-argcomplete')
makedepends=('python-setuptools')
source=("https://gitlab.com/postmarketOS/pmbootstrap/-/archive/$pkgver/pmbootstrap-$pkgver.tar.gz")
sha512sums=('af7febd7a43227492a5363ef255344de5075e6189f1402199d62ac329d5ce2e3a435e8f9f421937640bf3f95a650b12b6c10308cce1b336627a3fda92ba900c0')

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1 --skip-build
}

# vim: ts=2 sw=2 et:
