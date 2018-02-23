# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Philipp A. <flying-sheep@web.de>

_pkgname=aiohttp
pkgname=python-aiohttp
pkgver=3.0.1
pkgrel=1
pkgdesc='HTTP client/server for asyncio'
url='https://aiohttp.readthedocs.io'
arch=('x86_64')
license=('Apache')
depends=('python' 'python-chardet' 'python-multidict' 'python-async-timeout' 'python-yarl' 'python-idna_ssl' 'python-attrs')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-pytest-mock')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/aiohttp/archive/v${pkgver}.tar.gz)
sha256sums=('3b21b52f5798e0c3e2f51c16a2a7e87673ca99b36f292fa3d2fdadc440392336')
sha512sums=('ba3dd7fb2044eacfbdff77efa14e2affef57e810d5cd0ef44b8f1cbab4760b4ca4ac588dd89e2704b2a2d2f941a08f7cecadba1c067a1b8a244e47cd4b2497eb')

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
