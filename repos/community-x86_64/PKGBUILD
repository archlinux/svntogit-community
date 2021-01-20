# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_pkgname=yarl
pkgname=python-yarl
pkgver=1.6.3
pkgrel=1
pkgdesc='Yet another URL library'
url='https://github.com/aio-libs/yarl/'
arch=('x86_64')
license=('Apache')
depends=('glibc' 'python' 'python-multidict' 'python-idna' 'python-typing_extensions')
makedepends=('cython' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner')
source=(https://github.com/aio-libs/yarl/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('cf69f865d7ae6e0632a17d8c18ef91194dc272d03c30fb62d2fb32be2a23842f5d384107f5da54414c17d007cdc016a5170b65217eb91fddba1cf1d52c2c85fc')
b2sums=('afd2a9412d00287462704ef4a01f95f1c2b39625621fac144f8a025e2da0eb58fc5e9c5d1831d0837b3f4c9f9b82faa19cb81c78113efb37640a812b433c2f82')

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
