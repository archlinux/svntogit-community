# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pyname=aiosignal
pkgname=python-${_pyname}
pkgver=1.2.0
pkgrel=3
pkgdesc='List of registered asynchronous callbacks'
url='https://github.com/aio-libs/aiosignal'
arch=('any')
license=('Apache')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-pytest-asyncio')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('e75df2fcaeeea7ff7688c20838600f6315bec25b82c48ed7a23b7853edd3d53d72f76a686ad9b0d856f43b0d476398196a8ce4eb98c8859234710ff008f8ba42')
b2sums=('02657c11f5ee96173c94ab889993f835904a79e3fee58121fb332583f8d81cb680087e667dc0f8e89cd9704bc338362f2878bef7080907a5a3f86bef7a30cac1')

build() {
  cd "${_pyname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${_pyname}-${pkgver}"
  python setup.py test
}

package() {
  cd "${_pyname}-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 CHANGES.rst README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
