# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.4.2
pkgrel=1
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('f86ccaee2a5e50daf704ee6f26515291efdad4acfcb38ec831364ec085ce78607c1ff13311d5f4c04b798afb0703801203e97412ff5cfae5ca50a301a7a389d3')

build() {
  cd jeepney-$pkgver
  python setup.py build
}

package() {
  cd jeepney-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
