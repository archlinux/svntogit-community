# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=1.5.2
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python2-contextlib2'
             'python2-pathlib2' 'python2-configparser' 'python-zipp' 'python2-zipp')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-importlib_resources' 'python-wheel' 'python2-wheel' 'python-pyfakefs')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/v$pkgver/importlib_metadata-v$pkgver.tar.bz2")
sha512sums=('a2d007fe541493a665170a746b6e0613b71a07f0a032affddb5562c57b8b28c439d108c934dd5a44da451e5f0a03c1d707ee0eae5cc079450f9d8fd7c000b817')

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
