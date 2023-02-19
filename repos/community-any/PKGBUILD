# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.14.0
_commit=44bf8757105b6687db196feae8090c24f367cc7f
pkgrel=1
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
