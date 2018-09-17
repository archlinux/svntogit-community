# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=0.4
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python2-typing' 'python2-pathlib2'
             'python-wheel' 'python2-wheel')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-contextlib2' 'python2-importlib_resources')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/$pkgver/importlib_metadata-$pkgver.tar.bz2")
sha512sums=('71381273b203d8a3a538bc1916f44e741fb04b87f607adb5ed1679e0e13386327bc4c2186b23d66535ce7a241fd1ebfe1e3f604e64576679a57abee34a1f620a')

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
  depends=('python-wheel' 'python-setuptools')

  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-importlib-metadata() {
  depends=('python2-wheel' 'python2-setuptools' 'python2-typing' 'python2-pathlib2')

  cd importlib_metadata-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
