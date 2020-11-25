# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.6.0
pkgrel=4
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
checkdepends=('python-pytest' 'python-pytest-trio' 'python-pytest-asyncio' 'python-testpath'
              'python-trio')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('140be9dd28ed853d2d41b6a8bbeb2f22c0270ce7bf33b943ec2ac010db17d4f06e253fa8637fbbb3044fe9ffdbfa1e15f0c663eb44bdd538f8c47c2e7dab3ca5')

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
