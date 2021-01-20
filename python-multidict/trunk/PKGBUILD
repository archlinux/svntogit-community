# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=5.1.0
pkgrel=1
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(https://github.com/aio-libs/multidict/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('7dfc8862048d274f37341dda72d93c0fab6d5463fade4f5e241f5b8bf65dcea5c0b5120376847a77f00c7246e87a1cfe14502b6f64bf97e4d00594fed6735466')
b2sums=('9b9194447a7d91d673b07e440d5f1d2068c79b15890c63a5ab679016b02471996adc73173bb303c14609b2aec230d8ebda36ab978b22b67c008f6b03e6f663f2')

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
