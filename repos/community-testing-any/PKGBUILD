# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-click-default-group
pkgver=1.2.2
pkgrel=3
pkgdesc="Extends click.Group to invoke a command without explicit subcommand name"
url="https://github.com/click-contrib/click-default-group"
license=('BSD')
arch=('any')
depends=('python-click')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/click-contrib/click-default-group/archive/v$pkgver.tar.gz")
sha512sums=('6f296d154813e0c3dbf8e435c4c1b4394f51a000320c5585aeb78b81f30fe15bd27a8aad0fdbb71fccb88dc3083682519f1dd06572c8d5c35639fb9c3acf73fa')

build() {
  cd click-default-group-$pkgver
  python setup.py build
}

check() {
  cd click-default-group-$pkgver
  python -m pytest
}

package() {
  cd click-default-group-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
