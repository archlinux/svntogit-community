# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=3.0.0
pkgrel=2
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-asyncio' 'python-pytest-aiohttp')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/async-timeout/archive/v${pkgver}.tar.gz
        ${pkgname}-python37.patch::https://github.com/aio-libs/async-timeout/pull/51.patch)
sha256sums=('48341ca53e51d5e975154e14f3d75444355243482c7319bb95b727a487d92cc8'
            '1e0178049691d76ec8129a9c14cfcc5de39803168765fa1d7ddbb045da16548b')
sha512sums=('23a697ef1aea14e74fdca2f1d18a0dd474caa623c452199da137db01692a28be9667f50d0253b61743fdff00bea2880fc59439f27ffc1a7257ce2d13fdab23a5'
            'f0303da9e9b6b5f2dc311c19b9dc48f1726bdbf6796272e64ddc005df57b1d390fd9fffbf85938cb33445ad0d330485a4b5ec9153a1b5889146193d9cd8d00ab')

prepare() {
  cd ${_pkgname}-${pkgver}
  # https://github.com/aio-libs/async-timeout/pull/51
  patch -p1 -i ../${pkgname}-python37.patch
}

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
