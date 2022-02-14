# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.9.0
pkgrel=1
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("https://github.com/rbarrois/python-semanticversion/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('6db53e9993b635a7bb2e2b168329d359136d914fb146aa5102a5cd0e8395978942fa84e7bed0fdb00b1768b1acd38e1a1b0cedfdc2efc073dddf4973178043db')

build() {
  cd python-semanticversion-$pkgver
  python setup.py build
}

check() {
  cd python-semanticversion-$pkgver
  python setup.py egg_info
  pytest
}

package() {
  cd python-semanticversion-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
