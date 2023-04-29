# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgname=python-colorama
pkgver=0.4.6
pkgrel=2
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-hatchling')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('2b269b190041398a1808b0b5147e47422b4451a1bc91841d0957572214ba8addd731c8932afdc60bfbba9833a0fe6c9c5c2ecb150613f13498f661799d625e4f')

build() {
  cd colorama-$pkgver
  python -m build -nw
}

check() {
  cd colorama-$pkgver
  python -m unittest discover -p *_test.py
}

package() {
  cd colorama-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
