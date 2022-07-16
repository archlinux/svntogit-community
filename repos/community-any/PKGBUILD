# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.text
pkgver=3.8.1
pkgrel=1
pkgdesc='Module for text manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.text'
license=('MIT')
depends=('python-jaraco.functools' 'python-jaraco.context')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.text/jaraco.text-$pkgver.tar.gz")
sha512sums=('2dfdd2b3bfef7c0a38a633b810a63a4337ce79b0c871f08beb369bea04585ef1b9e53afa7cef0b54c172ca25eed068af92215526d2f5cee232ccf7e72c914cfa')

build() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m build --wheel --no-isolation
}

package() {
  cd "$srcdir/jaraco.text-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
