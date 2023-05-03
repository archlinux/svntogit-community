# Maintainer: Bruno Pagani <archange@archlinux.org>

_pkg=pytest-dependency
pkgname=python-${_pkg}
pkgver=0.5.1
pkgrel=4
pkgdesc="Manage dependencies of tests"
arch=(any)
url="https://github.com/RKrahl/pytest-dependency"
license=(Apache)
depends=(python-pytest)
makedepends=(python-setuptools)
source=(https://files.pythonhosted.org/packages/source/${_pkg::1}/${_pkg}/${_pkg}-${pkgver}.tar.gz
        ${pkgname}-fix-pytest-6.2.patch::${url}/commit/0930889a13e2b9baa7617f05dc9b55abede5209d.patch)
sha256sums=('c2a892906192663f85030a6ab91304e508e546cddfe557d692d61ec57a1d946b'
            '3a107ea61e9f95cc4cc247dacef264b1600e41c0a7515817cd0e0b563516a3a3')

prepare() {
  cd ${_pkg}-${pkgver}
  patch -p1 < ../${pkgname}-fix-pytest-6.2.patch
}

build() {
  cd ${_pkg}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkg}-${pkgver}
  PYTHONPATH="${PWD}/build/lib" pytest -v --color=yes
}

package() {
  cd ${_pkg}-${pkgver}
  python setup.py install --prefix=/usr --root="${pkgdir}" --skip-build --optimize=1
}
