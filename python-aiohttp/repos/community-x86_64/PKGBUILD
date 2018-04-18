# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=3.1.3
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl' 'python-idna_ssl' 'python-attrs')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock' 'python-async_generator')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('876d74ee986051590cf4af90365fe4268a19586a72024551e84ce6c0c5d11bfa')
sha512sums=('50c6d24a1ad665e58d3f2a5b438f4aa6ffc23139c087b2fb7a239272e64cc2b03fb1bf396eba189f57b340dcebb8cb0d30853d6e3c873fc2d59d38606fb67bda')

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
