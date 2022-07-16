# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.classes
pkgver=3.2.2
pkgrel=1
pkgdesc='Module for classes manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.classes'
license=('MIT')
depends=('python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest-black' 'python-pytest-checkdocs' 'python-pytest-cov'
              'python-pytest-enabler' 'python-pytest-flake8' 'python-pytest-mypy'
              'python-pip')
conflicts=(python-jaraco)
replaces=(python-jaraco)
source=("https://files.pythonhosted.org/packages/source/j/jaraco.classes/jaraco.classes-$pkgver.tar.gz")
sha512sums=('56eaf8420f0319137ecae04c61e5a866909b83d3638343ea45ed3739524c8314bb6aac7ee9b5f899e2a1a5238c2caeaa971ed1cd0dbd28d9ac01ad6716549deb')

build() {
  cd "$srcdir/jaraco.classes-$pkgver"
  python -m build --wheel --no-isolation
}

check() {
  cd "$srcdir/jaraco.classes-$pkgver"
  python -m pytest
}

package() {
  cd "$srcdir/jaraco.classes-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
