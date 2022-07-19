# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-issues
_pyname=${pkgname/python-/}
pkgver=3.0.1
pkgrel=1
pkgdesc="Sphinx extension for linking to your project's issue tracker"
url='https://github.com/sloria/sphinx-issues'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=(https://github.com/sloria/sphinx-issues/archive/${pkgver}/${_pyname}-${pkgver}.tar.gz)
sha512sums=('dd64e1611eb58fc455bedb1658473fd71e4deab1371d8a42e6fa7fe3b128a991251add12e463b9a5826fd4eb5aa12e9a117dcf953feeb8df980a7951e43d8baa')

build() {
  cd ${_pyname}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pyname}-${pkgver}
  PYTHONPATH="$PWD" py.test
}

package() {
  cd ${_pyname}-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
