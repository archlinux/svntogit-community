# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.8.1
pkgrel=3
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-pip' 'python-pytest' 'python-importlib_resources'
              'python-pyfakefs' 'python-tests')
source=("https://github.com/python/importlib_metadata/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('a183a16511b4bb5984474684911d7b038f8714049797e9e92ab2b0264c492f55a3c894fdd516da035465ca098b4cfe259eb1bebff74861756819bfb5a54ca198')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  # remove pytest-perf warmup to be able to drop its dependency
  rm importlib_metadata-$pkgver/exercises.py
}

build() {
  cd importlib_metadata-$pkgver
  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python -m pytest -k 'not test_find_local'
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
