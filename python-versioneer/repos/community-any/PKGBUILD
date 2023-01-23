# Maintainer: George Rawlinson <grawlinson@archlinux.org>

pkgname=python-versioneer
pkgver=0.28
pkgrel=1
pkgdesc='A tool for managing a recorded version number in setuptools-based python projects'
arch=('any')
url='https://github.com/python-versioneer/python-versioneer'
license=('custom:Unlicense')
depends=('python' 'python-setuptools' 'python-tomli') # tomli: remove once we move to python 3.11
makedepends=(
  'git'
  'python-build'
  'python-installer'
  'python-wheel'
)
_commit='83f20fdf886df7a6089fca3bb7fc3c33198bd629'
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

  python setup.py make_versioneer
  python -m unittest discover test
}

package() {
  cd "$pkgname"

  python -m installer --destdir="$pkgdir" dist/*.whl

  # license
  install -vDm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE
}
