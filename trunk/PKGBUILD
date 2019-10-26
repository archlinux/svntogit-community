# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-issues
_pyname=${pkgname/python-/}
pkgver=1.2.0
pkgrel=2
pkgdesc="Sphinx extension for linking to your project's issue tracker"
url='https://github.com/sloria/sphinx-issues'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=(https://github.com/sloria/sphinx-issues/archive/${pkgver}/${_pyname}-${pkgver}.tar.gz)
sha512sums=('8814e910b111f0b241bc40a93de8b6ff1acd24437f1b014b24691b3bbaaadaadaded82175067d8992bb482f4bfcdec570cdd26b4c6858d7af60d5dd3f0638b64')

build() {
  cd ${_pyname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pyname}-${pkgver}
  PYTHONPATH=. py.test
}

package() {
  cd ${_pyname}-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
