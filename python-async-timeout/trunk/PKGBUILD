# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=4.0.1
pkgrel=2
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-asyncio' 'python-pytest-aiohttp')
source=(https://github.com/aio-libs/async-timeout/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('21e6caad3792d3c4b1ee8bf9bda8b63222afe4d38ab7bae0146ee38475afc279')
sha512sums=('fccd09c1d90bdf594649f52cd3b9f8da13f3456af43437f031dce43b1ee4a70e90479122a6599929fe1e1fe98a88a0d8d775ce153783dfed180571fb842fbb5a')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  PYTHONPATH=. py.test tests
}


package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
