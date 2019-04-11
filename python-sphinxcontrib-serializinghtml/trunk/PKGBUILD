# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-serializinghtml
pkgname=python-sphinxcontrib-serializinghtml
pkgver=1.1.3
pkgrel=1
pkgdesc='Sphinx extension which outputs "serialized" HTML files (json and pickle)'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-serializinghtml
license=('BSD')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('c0efb33f8052c04fd7a26c0a07f1678e8512e0faec19f4aa8f2473a8b81d5227')

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
