# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-jsmath
pkgname=python-sphinxcontrib-jsmath
pkgver=1.0.1
pkgrel=1
pkgdesc='Sphinx extension which renders display math in HTML via JavaScript'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-jsmath
license=('BSD')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('a9925e4a4587247ed2191a22df5f6970656cb8ca2bd6284309578f2153e0c4b8')

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
