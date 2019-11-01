# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: renek <aur@spaceshore.net>

_pkgname=multidict
pkgname=python-${_pkgname}
pkgver=4.5.2
pkgrel=2
pkgdesc='Asyncio-based multidict implementation for Python'
url='https://github.com/aio-libs/multidict'
arch=('x86_64')
license=('APACHE')
depends=('python' 'glibc')
makedepends=('cython' 'python-setuptools' 'git')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-pytest-runner' 'python-psutil' 'python-perf')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/aio-libs/multidict/archive/v${pkgver}.tar.gz
        multidict-python-3.8.patch::"https://github.com/aio-libs/multidict/commit/49e1613a.patch")
sha256sums=('09be72d0c223be82aa5ed42766665048c329dba9f4440cd2b9633f78e12b28da'
            '2ff9957947e77109b002974b9d162f7f483501b15bc3fb768c8feb192f2cf970')
sha512sums=('ec66cf3c57e3386e07e45641536a6eeb94e9707d8a0d3b485d22b8687f20282c9115d533c7b0e9fb6dba28b923cf68dd8cdda08c75e78ca4eca2f0c3ec23c58f'
            '471e16d81214045cf06674690234348f1c67c0db99740d2a0bfcbc3c100387b0ace43a84e3f8451e435e7c3a1f17b63f51d44dab12a3851ed686539d13c50689')

prepare() {
  cd $_pkgname-$pkgver
  git apply ../multidict-python-3.8.patch # Add test files for python 3.8
}

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
