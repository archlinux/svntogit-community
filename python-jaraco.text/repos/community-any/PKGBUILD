# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.text
pkgver=3.10.0
pkgrel=1
pkgdesc='Module for text manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.text'
license=('MIT')
depends=('python' 'python-jaraco.functools' 'python-jaraco.context' 'python-autocommand' 'python-inflect' 'python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.text/jaraco.text-$pkgver.tar.gz")
sha512sums=('1c83dc9247e8c55ed20d8768abcb66c3fb4cdfb9ade3744f3d3c3e705b94e376c7b44fdfe242189001d69fbf28fdb5601ff33b1874495b3c2ad9bdd781265f43')

build() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m build --wheel --no-isolation
}

check() {
  cd "$srcdir/jaraco.text-$pkgver"
  PYTHONPATH="$PWD" pytest
}

package() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
