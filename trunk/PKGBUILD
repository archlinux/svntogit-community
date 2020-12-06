# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.1.1
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
sha512sums=('ddebb9b785afb0da6bcb4c5e226efd57b80951b17a180fed623f049b0aa75864815020cd7b0c08794573e09768bd4b801551f267f257d999ac2b15a6be5d30e0')

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

