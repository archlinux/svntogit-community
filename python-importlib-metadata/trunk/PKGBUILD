# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-importlib-metadata
pkgver=3.2.0
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
sha512sums=('ca41ff9690628e3483da3024e96c4118282e970c98ce8572854fdd1f1d14464590742d3cf7219c5014fd7b05861f6dcb3800d6313c7c5a047b2ff605d06f73cd')

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

