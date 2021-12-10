# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=python-sphinx-autodoc-typehints
_pyname=${pkgname/python-/}
_gitcommit=1b85ff5306f02985ab00c73b41504bb5b17943eb
pkgver=1.12.0
pkgrel=1
pkgdesc='Type hints support for the Sphinx autodoc extension'
url='https://github.com/agronholm/sphinx-autodoc-typehints'
arch=('any')
license=('MIT')
depends=('python' 'python-sphinx' 'python-typing_extensions')
makedepends=('git' 'python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-sphobjinv')
source=("git+https://github.com/agronholm/sphinx-autodoc-typehints#commit=${_gitcommit}"
         python-3.10.patch)
sha512sums=('SKIP'
            'c5fca0339d1ad2e0226006396c7e39f66e71d02e11dd883f8e4ee2c195293cf54afa8e13ef0164e7249ee9d8a296314b5c7ad4d707688855838cd4e3de1bba44')

pkgver() {
  cd ${_pyname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  patch -d $_pyname -p1 < python-3.10.patch # Fix tests with Python 3.10 and Sphinx 4
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
