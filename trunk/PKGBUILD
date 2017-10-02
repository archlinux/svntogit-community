# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=0.13.0
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('i686' 'x86_64')
license=('Apache')
depends=('python' 'python-multidict')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('b15e1627046d02905187dd51b7869eef00dd3dbad7e31bc49de5813a66c53561')
sha512sums=('8e45cc8dba7381ac2bf6212e8ddf62b24e94f3200b6388eb7cd67f118d93b3210b09deb39e2044d2467376cfc759105b5c001d574caf8228b2154003c484b049')

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
