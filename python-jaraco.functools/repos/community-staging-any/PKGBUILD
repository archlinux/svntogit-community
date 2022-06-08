# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.functools
pkgver=3.5.0
pkgrel=1
pkgdesc='Functools like those found in stdlib'
arch=('any')
url='https://github.com/jaraco/jaraco.functools'
license=('MIT')
depends=('python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
conflicts=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.functools/jaraco.functools-$pkgver.tar.gz")
sha512sums=('7257f41506f90ca2fda1bd12fed58fa4d4ff5738547f8cdae8ccad1901e0c818afb701dd8e9050fc77ca1271bc2466d5a542990138bc3db2cf9b04d12850844c')

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
