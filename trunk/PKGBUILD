# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=0.7
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python2-contextlib2' 'python2-pathlib2')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-importlib_resources')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/$pkgver/importlib_metadata-$pkgver.tar.bz2")
sha512sums=('67c41d3b59129b5bc7658a1797fe2595e9ee1919b81d77c15855560a48c90156e642eacb934c7004c3d851aecd9ed8588767afbacc04fae7a3ddfbef17a39fca')

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
