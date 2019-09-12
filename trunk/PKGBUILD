# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=0.22
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python2-contextlib2'
             'python2-pathlib2' 'python2-configparser' 'python-zipp' 'python2-zipp')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-importlib_resources' 'python-wheel' 'python2-wheel')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/$pkgver/importlib_metadata-$pkgver.tar.bz2")
sha512sums=('9f5ecf54c5ee0c3c9059f7378197fa3b7fd9fd6ff19597b6faf32ef1fceb6a8282215cf1572cabd252736c72ae7b4d1f0d026a60f7ded7d64990e3f12ef8c7be')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cp -a importlib_metadata-$pkgver{,-py2}
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
  depends=('python-zipp')

  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-importlib-metadata() {
  depends=('python2-zipp' 'python2-configparser' 'python2-contextlib2' 'python2-pathlib2')

  cd importlib_metadata-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
