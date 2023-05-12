# Maintainer: George Rawlinson <grawlinson@archlinux.org>

pkgname=python-puremagic
pkgver=1.15
pkgrel=1
pkgdesc="A Python module that will identify a file based off it's magic numbers"
arch=('any')
url='https://github.com/cdgriffith/puremagic'
license=('MIT')
depends=('python')
makedepends=(
  'git'
  'python-build'
  'python-installer'
  'python-setuptools'
  'python-wheel'
)
checkdepends=('python-pytest')
_commit='ff042db17e7477bbabcb9c5b7e8562a697f6b1cb'
source=("$pkgname::git+$url#commit=$_commit")
b2sums=('SKIP')

pkgver() {
  cd "$pkgname"

  git describe --tags | sed 's/^v//'
}

build() {
  cd "$pkgname"

  python -m build --wheel --no-isolation
}

check() {
  cd "$pkgname"

  PYTHONPATH="$PWD:$PYTHONPATH" pytest
}

package() {
  cd "$pkgname"

  python -m installer --destdir="$pkgdir" dist/*.whl

  # license
  install -vDm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE
}
