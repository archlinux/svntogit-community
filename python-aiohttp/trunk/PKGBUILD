# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=2.2.3
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('i686' 'x86_64')
license=('Apache')
depends=('python>=3.4.2' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz
        ${pkgname}-fix-multidict-3.1.patch::https://github.com/aio-libs/aiohttp/commit/075c34c8f98d3690f7167d8f885bfbd3d74dd67a.patch)
sha256sums=('3cbd7c44ae455d9e0196b3818b66097f4566563f5c00c34cf478c68a5542d371'
            '4e98ff7b86e7c35669ad0c88a984fa6d33d1f8332d9b58cb79c338a9862bcd4c')
sha512sums=('a3ad2b86c8b1024ba54df6b734fb387c37e914889145b1747c911a1c15e7c140bdd3eb0a4c384958b0517e8813d4b1dcf8c1c1151f3990f4945c897a2302fdc9'
            '66d320075ebb0f371b33af980b3a80ada9ba13c3ab0024594b5a43442bbfb4768a7716e182830477b7e89fd4d3c22a90d74398d8c6feaa1635dd18c5dbf2d387')

prepare() {
  cd ${_pkgname}-${pkgver}
  patch -p1 < "${srcdir}/${pkgname}-fix-multidict-3.1.patch"
}

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
