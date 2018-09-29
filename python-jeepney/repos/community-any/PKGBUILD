# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.4
pkgrel=1
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('43083994a7c6af84a5a68d3ff8f6dc4d9129ce9fa55517838fb62d9f62bb78bdf52067649d0b95d08d689b7d7475cb9b2a956662e265a776ad42dcf4ccc0ab63')

build() {
  cd jeepney-$pkgver
  python setup.py build
}

package() {
  cd jeepney-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
