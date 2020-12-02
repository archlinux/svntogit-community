# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-autodoc-typehints
_pyname=${pkgname/python-/}
_gitcommit=2fac99f455855c832b22a272edde3f9852ba6a04
pkgver=1.11.1
pkgrel=2
pkgdesc='Type hints support for the Sphinx autodoc extension'
url='https://github.com/agronholm/sphinx-autodoc-typehints'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx' 'python-typing_extensions')
makedepends=('git' 'python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-sphobjinv')
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
  PYTHONPATH=. pytest
}

package() {
  cd ${_pyname}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
