# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=1.6.1
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python2-contextlib2'
             'python2-pathlib2' 'python2-configparser' 'python-zipp' 'python2-zipp')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python-importlib_resources' 'python2-importlib_resources' 'python-wheel'
              'python2-wheel' 'python-pyfakefs')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/v$pkgver/importlib_metadata-v$pkgver.tar.bz2")
sha512sums=('0f813ea597f25a31c6810b23d2ebd0e46c098e2a15a3dde5fc2ca9f22e7e97cc4d15403d00e8d2be040d5da992fc44bc8ab752d965ee4c2cd4b6d129d6844561')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cp -a importlib_metadata-v$pkgver{,-py2}
}

build() {
  cd "$srcdir"/importlib_metadata-v$pkgver
  python setup.py build

  cd "$srcdir"/importlib_metadata-v$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/importlib_metadata-v$pkgver
  python setup.py pytest

  # pyfakefs dropped support for python 2.7
  #cd "$srcdir"/importlib_metadata-v$pkgver-py2
  #python2 setup.py pytest
}

package_python-importlib-metadata() {
  depends=('python-zipp')

  cd importlib_metadata-v$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-importlib-metadata() {
  depends=('python2-zipp' 'python2-configparser' 'python2-contextlib2' 'python2-pathlib2')

  cd importlib_metadata-v$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
