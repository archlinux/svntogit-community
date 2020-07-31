# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.5.0
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna' 'python-typing_extensions')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('0840bf2d1272ecc95f3dff67612698fbce88430202e70cc1c537fd899c6fcbee722a1fddc93749001d8d32c63a6de0fa60c4299c4ff790c2423904ae3172eb20')
b2sums=('f42e73398665042766efa9e5891c948e5fae5c21a53737f6db31ea3808792a5e2965488950b2749333394a02924a1ff973651c56d3539fb5722fe75daaa0132c')

prepare() {
  cd ${_pkgname}-${pkgver}
  sed 's| .install-cython ||g' -i Makefile
}

build() {
  cd ${_pkgname}-${pkgver}
  make cythonize
  LANG=en_US.UTF-8 python setup.py build
}

check() {
  cd ${_pkgname}-${pkgver}
  python setup.py test
}

package() {
  cd ${_pkgname}-${pkgver}
  LANG=en_US.UTF-8 python setup.py install --root="${pkgdir}" -O1 --skip-build
}

# vim: ts=2 sw=2 et:
