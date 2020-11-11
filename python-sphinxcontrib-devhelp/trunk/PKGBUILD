# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-devhelp
pkgname=python-sphinxcontrib-devhelp
pkgver=1.0.2
pkgrel=3
pkgdesc='Sphinx extension which outputs Devhelp document'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-devhelp
license=('BSD')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-sphinx')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('ff7f1afa7b9642e7060379360a67e9c41e8f3121f2ce9164266f61b9f4b338e4')

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
