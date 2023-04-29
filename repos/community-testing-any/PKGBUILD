# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.collections
pkgver=3.5.2
pkgrel=3
pkgdesc="Models and classes to supplement the stdlib 'collections' module."
arch=('any')
url='https://github.com/jaraco/jaraco.collections'
license=('MIT')
depends=('python-jaraco.text' 'python-jaraco.classes')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest-enabler' 'python-pytest-mypy')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.collections/jaraco.collections-$pkgver.tar.gz")
sha512sums=('9567ee44fbc5010cc81ee24de792e53b5a225759b5f7d2e7dd932b0cae38e2035fddb5bd3dee5dc08fea9c61e2bf9087418cd192d81c72760f1e0d95a7b3788c')

prepare() {
  cd jaraco.collections-$pkgver
  # https://github.com/jaraco/jaraco.collections/issues/10
  echo "explicit_package_bases = True" >> mypy.ini
}

build() {
  cd jaraco.collections-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd jaraco.collections-$pkgver
  python -m pytest
}

package() {
  cd jaraco.collections-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
