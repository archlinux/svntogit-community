# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.9
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('04a248d78021c45a1254f80966e6e4e6817ff3f8312d36fa9874c300fc106b7bed3600702a6953044f88cfa08f8ea8d6447c160554d8c1e1568051d3ce4a175b')

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
