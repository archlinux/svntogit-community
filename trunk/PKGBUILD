# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-htmlhelp
pkgname=python-sphinxcontrib-htmlhelp
pkgver=1.0.2
pkgrel=1
pkgdesc='Sphinx extension which renders HTML help files'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-htmlhelp
license=('BSD')
makedepends=('python-setuptools')
checkdepends=('python-html5lib' 'python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('4670f99f8951bd78cd4ad2ab962f798f5618b17675c35c5ac3b2132a14ea8422')

prepare() {
  cd $_name-$pkgver
  rm -r tests/__pycache__
}

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  pytest
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
