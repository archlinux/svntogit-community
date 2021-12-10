# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.7.1
pkgrel=3
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
checkdepends=('python-pytest' 'python-pytest-trio' 'python-pytest-asyncio' 'python-testpath'
              'python-trio' 'python-async-timeout')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('f0af5a18a669f1a6322925201cad83ee01bc5a1b91577565042fd8a18b506a3650ff67b0ba333c8fb3b179f43ef243d16b07a9a1f7a7e5baec825dda0e6b0571')

build() {
  cd jeepney-$pkgver
  python setup.py build
}

check() {
  cd jeepney-$pkgver
  pytest
}

package() {
  cd jeepney-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
