# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=4.7.6
pkgrel=3
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(https://github.com/aio-libs/multidict/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('5f90cb04fe2562884c331018a5002e1370e2596e0afd21e4289ab696847a3028a074bbaa6717b3905161f823f8592d6572475307039f8f97c1ac65aad815a6b0')
b2sums=('f08a45d4ce404dbb64d2561ee2328c0aa3a8fbf65483082c11e5e1554bec23e5c711da2350e241308a1239256b942ef6c420e6e51aef342b380cc01f84d4ca72')

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
