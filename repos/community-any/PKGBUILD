# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=2.0.0
pkgrel=1
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-asyncio' 'python-pytest-aiohttp')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/async-timeout/archive/v${pkgver}.tar.gz)
sha256sums=('6209cdbaacdd592978f53e4c9466a423e72f26c226a15d0d46791f856aca1a0f')
sha512sums=('e491308752cdba7c5fb569e59722b2bdb14a1a5f16866ad17b2546c55cee8782b00b16122e6c46dca704ff42459d454d3bfa8cfd8faffb2a6fc251f0080f975c')

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
  python setup.py install --skip-build -O1 --root="${pkgdir}"
}

# vim: ts=2 sw=2 et:
