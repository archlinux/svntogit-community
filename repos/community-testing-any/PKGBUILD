# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.4.1
pkgrel=3
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('46aed19fd29df724af0e78ec0acabeb196324444e682817c330f3fd290a52cf6a6cb639f8c76f4ef5311817c4e051d7231b4f26af3cb6768bdd8c4bec7589210')

build() {
  cd jeepney-$pkgver
  python setup.py build
}

package() {
  cd jeepney-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
