# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=2.3.6
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python>=3.4.2' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('1d9c5a6a27b462fe04430ceab0edd90b83535354a4fc9e8856719274cd89994c')
sha512sums=('967a533231f694f63077c0b0daf89f1973d45cf6e1a649b7b76f0386616f687148b542a1800d731cfcb03d0a464d5f1742a686e435a42a28c2a814cef5ec71b0')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  local PYTHONVERSION="$(python -c 'import sys; print("{}.{}".format(sys.version_info.major, sys.version_info.minor))')"
  PYTHONPATH="build/lib.linux-${CARCH}-${PYTHONVERSION}" \
    py.test
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
