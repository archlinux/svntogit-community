# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-applehelp
pkgname=python-sphinxcontrib-applehelp
pkgver=1.0.1
pkgrel=1
pkgdesc='Sphinx extension which outputs Apple help books'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-applehelp
license=('BSD')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('edaa0ab2b2bc74403149cb0209d6775c96de797dfd5b5e2a71981309efab3897')

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
