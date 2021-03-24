# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.7.3
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-pip' 'python-pytest' 'python-importlib_resources'
              'python-pyfakefs' 'python-tests')
source=("https://github.com/python/importlib_metadata/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('c05fdf95ad8c708bde27dcf00b41d5adf5e2af8230a32b285ff9fbc5720bb2fff97e18d9c5e3f2dd05d4ca7b9f7f6161713caa346ba7d4508401b05497f45cb4')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

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

