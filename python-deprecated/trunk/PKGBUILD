# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.7
pkgrel=2
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('da99a22410fdcc2a96cb5b15c489971078ce34e251406ae3dce6b3f97e284a4f09aaf1c5702407abe85a94cb6c8d9237f373a3096d6182e4a9cd1990be2817f1')

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
