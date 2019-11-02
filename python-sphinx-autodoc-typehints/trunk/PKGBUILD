# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-autodoc-typehints
_pyname=${pkgname/python-/}
_gitcommit=a1afbaba3067aee273ec0b14036e0f4ac44f79a9
pkgver=1.8.0
pkgrel=3
pkgdesc='Type hints support for the Sphinx autodoc extension'
url='https://github.com/agronholm/sphinx-autodoc-typehints'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx' 'python-typing_extensions')
makedepends=('git' 'python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest')
source=("git+https://github.com/agronholm/sphinx-autodoc-typehints#commit=${_gitcommit}")
sha512sums=('SKIP')

pkgver() {
  cd ${_pyname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

build() {
  cd ${_pyname}
  python setup.py build
}

check() {
  cd ${_pyname}
  PYTHONPATH=. py.test -k 'not test_sphinx_output'
}

package() {
  cd ${_pyname}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
