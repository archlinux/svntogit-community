# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.11
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('343f62a7a658569de885ac923a1de7f7b4cc5bf63d27d1b13474795ca38cc52932e35133b45d05c1b42d498af56f5945fad5c49b3cbdebda70337294da5d84c4')

build() {
  cd deprecated-$pkgver
  python setup.py build
}

check() {
  cd deprecated-$pkgver
  python setup.py pytest
}

package() {
  cd deprecated-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst -t "$pkgdir"/usr/share/licenses/$pkgname/
}
