# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.8
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('0a80775b3c9c52137ab22356ee1200d6b6faa7e202b85cd45fe99d58749569f4b6ebc53da0770c0bae1d59cc50dee7dd321b2e83bca85070a2d465080c399b03')

build() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py pytest
}

package() {
  cd deprecated-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
