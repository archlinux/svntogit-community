# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.12
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('ff9b03a35b688474b6d5390347c4acdf5e19fcee5f7fcbb61a456c6819adbcda72ce00200d55b92c65873addad5abf9d1d5617bf477f64beb08ca23f10ebaea2')

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
