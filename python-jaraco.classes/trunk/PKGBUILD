# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.classes
pkgver=3.2.1
pkgrel=1
pkgdesc='Module for classes manipulation'
arch=('any')
url='https://github.com/jaraco/jaraco.classes'
license=('MIT')
depends=('python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.classes/jaraco.classes-$pkgver.tar.gz")
sha512sums=('4c85cfdd1da88de01596867365147be6cadd7e1d230798683236fdfde579747e3309aac95ae4f3ef86c91bb4493f3096c4ecc14e3db764ef308aab41ead88e23')

build() {
  cd "$srcdir/jaraco.classes-$pkgver"
  python -m build --wheel --no-isolation
}

package() {
  cd "$srcdir/jaraco.classes-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
