# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jeepney
pkgver=0.7.0
pkgrel=1
pkgdesc="Low-level, pure Python DBus protocol wrapper"
url="https://gitlab.com/takluyver/jeepney"
license=('MIT')
arch=('any')
depends=('python')
checkdepends=('python-pytest' 'python-pytest-trio' 'python-pytest-asyncio' 'python-testpath'
              'python-trio')
source=("https://pypi.io/packages/source/j/jeepney/jeepney-$pkgver.tar.gz")
sha512sums=('b1fac480da0d8798b28eae30cb22ee97d4f73a11922f7b1bce86eebf938c2980414c2d026ef5a1cdcd95813724873700d348b04ba337aaac0706b2c8b38ea6c2')

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
