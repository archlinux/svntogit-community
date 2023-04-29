# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pluggy
pkgver=1.0.0
_commit=4259fdd799d64f953631e47ddcb69c3074a15c13
pkgrel=4
pkgdesc="Plugin and hook calling mechanisms for python"
arch=('any')
url="https://github.com/pytest-dev/pluggy"
license=('MIT')
depends=('python')
makedepends=('git' 'python-setuptools-scm')
checkdepends=('python-pytest')
source=("git+https://github.com/pytest-dev/pluggy.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd pluggy
  python setup.py build
}

check() {
  cd pluggy
  PYTHONPATH="$PWD"/src pytest
}

package() {
  cd pluggy
  python setup.py install -O1 --root "$pkgdir"
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
