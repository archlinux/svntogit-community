# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=0.12.0
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('i686' 'x86_64')
license=('Apache')
depends=('python' 'python-multidict')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('01f05ee4085feb53a89612bbf1bad58ce4cef0c67871a25e360f4023b5d5f86b')
sha512sums=('d8195b0f5c672960825efb6b3168f422207a373072eb66a406ec77c70117114d72f1e8fc41493e2ce49ba75ed5027e53325091a54da95bdac3135792d1daad37')

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
