# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=3.0.9
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl' 'python-idna_ssl' 'python-attrs')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('dd87b6854d766452bdd20b8117e5602418a104b1586697d38551880dfa1b738f')
sha512sums=('f5e1b775b49ba598d79cadb9429a485ee2aa1d677de8bf2a28394152c315dafc4bae404577d2da8e2dc12b5fdf5b0b6504d934886552e80fc970e24404b9678a')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  python setup.py test
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
