# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=0.6
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python2-contextlib2' 'python2-pathlib2')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-importlib_resources')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/$pkgver/importlib_metadata-$pkgver.tar.bz2")
sha512sums=('30262c9678d1b928d00d0cb497f7735d1f4b14c65a827ec8fc461322a1a2b81df84a5c5e970d0b578d865f469d8ee7cdacb1b3dde2176e4dda5649c4b193b54f')

prepare() {
  cp -a importlib_metadata-$pkgver{,-py2}
  cd importlib_metadata-$pkgver
  sed -i 's/importlib_resources/importlib.resources/' importlib_metadata/tests/test_zip.py
}

build() {
  cd "$srcdir"/importlib_metadata-$pkgver
  python setup.py build

  cd "$srcdir"/importlib_metadata-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/importlib_metadata-$pkgver
  python setup.py pytest

  cd "$srcdir"/importlib_metadata-$pkgver-py2
  python2 setup.py pytest
}

package_python-importlib-metadata() {
  depends=('python')

  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-importlib-metadata() {
  depends=('python2-contextlib2' 'python2-pathlib2')

  cd importlib_metadata-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
