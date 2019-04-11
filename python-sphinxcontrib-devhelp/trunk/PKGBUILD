# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=sphinxcontrib-devhelp
pkgname=python-sphinxcontrib-devhelp
pkgver=1.0.1
pkgrel=1
pkgdesc='Sphinx extension which outputs Devhelp document'
arch=('any')
url=https://github.com/sphinx-doc/sphinxcontrib-devhelp
license=('BSD')
depends=('python-sphinx')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('6c64b077937330a9128a4da74586e8c2130262f014689b4b89e2d08ee7294a34')

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
