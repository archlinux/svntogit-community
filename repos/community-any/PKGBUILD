# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=4.5.0
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
sha512sums=('43ffd4fee8c2792a1bc6041584e3a49a8fb4b686247ab429bc082f9873d87f31715298bf50661f532946b919fa1183a5f639b1cc6159a3021975151ae0960dcd')

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

