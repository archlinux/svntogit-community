# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.8.2
_commit=b8b6f2bdf673bbc404769c8ad749fcd9374af691
pkgrel=2
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('git' 'python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-timeout')
source=("git+https://github.com/benediktschmitt/py-filelock.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd py-filelock
  python setup.py build
}

check() {
  cd py-filelock
  PYTHONPATH=src pytest tests
}

package() {
  cd py-filelock
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
