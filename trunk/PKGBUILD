# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.15.0
_commit=63bdf88e27717fea6924664f1cb3c30b7875f0ea
pkgrel=2
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-jaraco.itertools' 'python-more-itertools' 'python-big-o')
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
