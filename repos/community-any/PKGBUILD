# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=1.4.0
pkgrel=1
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/async-timeout/archive/v${pkgver}.tar.gz)
sha256sums=('627366ef67f2a5dcab7e7d672794db3c70bddaac13d200a21883c37578b85221')
sha512sums=('82b67cdc0bf791936a3d775cfa7594d7ef6a21c3b0b5390901577aa4a4f24435b7fcabf9550fbfb36ee5739df0d9c98e4cda4d1e3f71eb8e2c5a8f2afd1ce48b')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --skip-build -O1 --root="${pkgdir}"
}

# vim: ts=2 sw=2 et:
