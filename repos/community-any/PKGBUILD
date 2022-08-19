# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.text
pkgver=3.9.1
pkgrel=1
pkgdesc='Module for text manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.text'
license=('MIT')
depends=('python-jaraco.functools' 'python-jaraco.context' 'python-autocommand' 'python-inflect' 'python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.text/jaraco.text-$pkgver.tar.gz")
sha512sums=('f850125c7612342772d5a4a68076ea53a8cad6015c8bbe7e2923b034f8f601c8ff974eec0069b1bacba115d0aa43a948aea3b79f61d773464c823aac1880bbf1')

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
