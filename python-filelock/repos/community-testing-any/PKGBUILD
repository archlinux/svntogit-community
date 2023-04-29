# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.12.0
_commit=b4713c946cf8bcd65276bffbccef8f269d504dbd
pkgrel=2
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('git' 'python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs')
checkdepends=('python-pytest' 'python-pytest-timeout' 'python-pytest-mock')
source=("git+https://github.com/benediktschmitt/py-filelock.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd py-filelock
  python -m build --wheel --no-isolation
}

check() {
  cd py-filelock
  PYTHONPATH=src pytest tests
}

package() {
  cd py-filelock
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
