# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=2.3.9
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python>=3.4.2' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('3044eed412a7100ba5c9ef61a06e0264ae159a4cb007339e0e98812dd45ae83d')
sha512sums=('628d60cb3aee209ef15ead381af16d7a46048207ec9c83f5657b26022ac5161789da391f3a9d4baa7fcfeb05f9564ea81f2095fb1bdca62f50914f2e34039409')

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
