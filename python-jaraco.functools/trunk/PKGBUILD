# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.functools
pkgver=3.5.2
pkgrel=1
pkgdesc='Functools like those found in stdlib'
arch=('any')
url='https://github.com/jaraco/jaraco.functools'
license=('MIT')
depends=('python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.functools/jaraco.functools-$pkgver.tar.gz")
sha512sums=('3f67d151f4f6553b3e560b0e6ab71cf726d6c8f36ef5e9f69b6325605547797e19a3f9eb1331cf332db498538953ccaeb75820528e6599fd7cf125abdc073e69')

build() {
  cd "$srcdir/jaraco.functools-$pkgver"
  python -m build --wheel --no-isolation
}

package() {
  cd "$srcdir/jaraco.functools-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
