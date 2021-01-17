# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.4.0
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
depends=('python-zipp')
makedepends=('python-setuptools-scm')
checkdepends=('python-pip' 'python-pytest-runner' 'python-importlib_resources'
              'python-wheel' 'python-pyfakefs' 'python-tests')
source=("$pkgname-$pkgver.tar.gz::https://github.com/python/importlib_metadata/archive/v$pkgver.tar.gz")
sha512sums=('513da876f4b14bd65e66ac3bf48e790b32c1c189976e1fac9b1d993225238688b56ac5dec813131772a6192030896bdd43e84bcda1911c972764de9674b36162')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd importlib_metadata-$pkgver
  python setup.py build
}

check() {
  cd importlib_metadata-$pkgver
  python setup.py pytest
}

package_python-importlib-metadata() {
  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

