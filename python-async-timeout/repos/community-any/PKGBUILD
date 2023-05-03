# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=4.0.2
pkgrel=3
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python' 'python-typing_extensions')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-asyncio' 'python-pytest-aiohttp')
source=(https://github.com/aio-libs/async-timeout/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('1eb41fc35a0a24461b00f3479553972c99300e194eb212ff8b816c90c084d1d4')
sha512sums=('d7c6c3bdeb5cfc8bbe8ceae290a386c05873e08c8ad9e383d96c5c8f4da2ab165fa0ba70edc7f5b861f80a44db3c51d32dbafd64af5c01d374fbe0cb5f608196')

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
