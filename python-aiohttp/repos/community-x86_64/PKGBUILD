# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=2.1.0
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('i686' 'x86_64')
license=('Apache')
depends=('python>=3.4.2' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('54f616090688169928b25068168e69b74dcee47b93d2400fa38f97b8d5a1402b')
sha512sums=('cb4a56431380a182a4c34319deb7dd6be2f85836da80994f4cb9538ab111836bbdbf5f1e9ad560b88cb9ee4c26cd01f2b0668906c181ff78d1be32a92a0ba7ea')

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

