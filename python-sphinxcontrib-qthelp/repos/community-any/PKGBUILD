# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-qthelp
pkgname=python-sphinxcontrib-qthelp
pkgver=1.0.3
pkgrel=3
pkgdesc='Sphinx extension which outputs QtHelp document'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-qthelp
license=('BSD')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('4c33767ee058b70dba89a6fc5c1892c0d57a54be67ddd3e7875a18d14cba5a72')

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
