# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-nodeenv
pkgver=1.3.5
pkgrel=1
pkgdesc="Node.js virtual environment builder"
url="https://github.com/ekalinin/nodeenv"
license=('BSD')
arch=('any')
depends=('python' 'make')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-coverage' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/ekalinin/nodeenv/archive/$pkgver.tar.gz")
sha512sums=('c7e9068a220f183a217b15e724aa8197fca8f2234c76eafd230899963b6796e66e151c20c529e6540f7e3c59849bda3860d563b38f5feeff73601043f79cfba0')

build() {
  cd nodeenv-$pkgver
  python setup.py build
}

check() {
  cd nodeenv-$pkgver
  python setup.py pytest
}

package() {
  cd nodeenv-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
