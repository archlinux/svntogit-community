# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.20.18
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-setuptools' 'python-urllib3')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('0131387f9b99aecc69ac98655b3931f2ad43da53d3a63e050fa3a6d6260ac554')
b2sums=('891a02380eae06f2a6331825f6380917c0fd43b418149c30f640566f76b49996f79c7295215d3cf006af86d8ed5bd1465696bcbe402dcfd6b68748043eb4e376')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$pkgver
  export PYTHONHASHSEED=0
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
