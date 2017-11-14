# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=0.14.2
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-multidict' 'glibc')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('869b9345468db4e51f719313778153415daab9a0689f78624731435a1507e3c6')
sha512sums=('088d582b897ed0072a270367ade80835631a263e69b31fd99f80ce03cd7f96e9c94487461a3433f29f369ccfbcaffabbad4c6ed9e3c5d4e74d26c1ffcd0df57b')

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
