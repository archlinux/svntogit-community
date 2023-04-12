# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=5.0.0
_commit=009ace37032742922d5fa04c62f04cea703ade2d
pkgrel=5
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-pyfakefs' 'python-pip' 'python-tests')
source=("git+https://github.com/python/importlib_metadata.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd importlib_metadata
  python -m build -nw
}

check() {
  cd importlib_metadata
  python -m pytest --ignore exercises.py
}

package() {
  cd importlib_metadata
  python -m installer -d "$pkgdir" dist/*.whl
}
