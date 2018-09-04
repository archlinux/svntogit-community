# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=4.4.0
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/multidict/archive/v${pkgver}.tar.gz)
sha256sums=('d2346c1ee53b352f3e51e80c14400853d13a32c01c497375ded16082fde97211')
sha512sums=('87350e298b2f9ccea08d884d41404fac7b47c5818ebb76059680e69df77dce05f6d2d18b24872ef5c846a383b7a81e0c36f44c69f19ff3d4f14881a4f88fb048')

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
