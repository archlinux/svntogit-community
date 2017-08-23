# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Stunts <f.pinamartins[at]gmail.com>
# Contributor: Phil Schaf <flying-sheep[at]web.de>
# Contributor: Carl George < arch at cgtx dot us >

_pkgname=async-timeout
pkgname=python-async-timeout
pkgver=1.3.0
pkgrel=1
pkgdesc='Asyncio-compatible timeout class'
url='https://github.com/aio-libs/async-timeout'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/async-timeout/archive/v${pkgver}.tar.gz)
sha256sums=('31b7d8e5c89870d0002c6faad79e39fcae9228523b33d3d0c84c0330b91c4b59')
sha512sums=('b2f8fee2589f46d67adefd30378f9d7b1a6d92f371ffbbe7b82fb9a34b9948c8d857a81152a097531ec7a6388a7bd1a1d55451bd104aa62c1df7af7fecaf7e14')

build() {
  cd ${_pkgname}-${pkgver}
  python setup.py build
}

package() {
  cd ${_pkgname}-${pkgver}
  python setup.py install --skip-build -O1 --root="${pkgdir}"
}

# vim: ts=2 sw=2 et:
