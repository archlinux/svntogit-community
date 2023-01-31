# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.12.0
_commit=ad532d5ed4a37f527eb546c3543e45c5a5ee8d36
pkgrel=2
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-jaraco.itertools' 'python-func-timeout' 'python-more-itertools')
source=("git+https://github.com/jaraco/zipp.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd zipp
  python -m build -nw
}

check() {
  cd zipp
  python -m unittest discover
}

package() {
  cd zipp
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
