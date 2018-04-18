# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=4.2.0
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/multidict/archive/v${pkgver}.tar.gz)
sha256sums=('e449839b6f272ec63687c3451dc6d3726491f6a267b701b1bf7549148aaa00c7')
sha512sums=('93f4b8553998b854b5b5c72018d1c54bb29d105f386742046e9078b54053c875168326daa9e326168dbccd1e814d5be4bc322fd7d64355c006d3ba38de93d5aa')

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
