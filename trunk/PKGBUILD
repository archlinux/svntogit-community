# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=1.2.1
pkgrel=2
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/async-timeout/archive/v${pkgver}.tar.gz)
sha256sums=('840ca2fb8237faa2251ecccdd8b5180d6f9f2d92df6068e77ea823642fcc75d4')
sha512sums=('f7109447ad7565f0caf0b0d561c934e0a79db471aeb78e5030e2e959af67749044e08bfb29ab32d10e8a9ca7dabb3194ac12cee18d3b1b4d7c3663221bade052')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --skip-build -O1 --root="${pkgdir}"
}

# vim: ts=2 sw=2 et:
