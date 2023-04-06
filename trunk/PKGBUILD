# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.8.0
pkgrel=2
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
checkdepends=('python-pytest' 'python-pytest-trio' 'python-pytest-asyncio' 'python-testpath'
              'python-trio' 'python-async-timeout')
makedepends=('python-build' 'python-installer' 'python-flit-core')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('823675f262c2c9778ccf9c1083601d936cca534fc0d2d9309b52aa6beeb7f73d225a37c5f18f6b0683c4829a93b1299a2cb4f8f341e55b92bedf58c8dce0aa75')

build() {
  cd jeepney-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd jeepney-$pkgver
  pytest
}

package() {
  cd jeepney-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
