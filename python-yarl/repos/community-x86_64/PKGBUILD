# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=0.18.0
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-multidict' 'glibc' 'python-idna')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('5a0b0787675d0c16c56cbec7ba434bfa5e73e28fe66fe534b2e0e45fdce95f21')
sha512sums=('e86dc19721ba66037c63828119785e70475318bcdce1ccd730b161deaf4d0e8713535c9066ee8cd7d786407ae21636ada6d322a4db7c18b53d5eb6a4a0077b09')

build() {
  cd ${_pkgname}-${pkgver}
  LANG=en_US.UTF-8 python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  local PYTHONVERSION="$(python -c 'import sys; print("{}.{}".format(sys.version_info.major, sys.version_info.minor))')"
  PYTHONPATH="build/lib.linux-${CARCH}-${PYTHONVERSION}" \
    py.test
}

package() {
  cd ${_pkgname}-${pkgver}
  LANG=en_US.UTF-8 python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
