# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=0.10.2
pkgrel=2
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('i686' 'x86_64')
license=('Apache')
depends=('python' 'python-multidict')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/yarl/archive/v${pkgver}.tar.gz)
sha256sums=('3ff138278de5a82fa434748c52d3c6871ca981821b6831013747b5368b431295')
sha512sums=('8180d5b927a3fd29ca5990fd954719e02e7825cd3c0b6a16016f170992e9e0adde09a2847894a6bd3914e3ec67a5cbbf5533ffee706370c9b748ccb4dc1dbd01')

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
