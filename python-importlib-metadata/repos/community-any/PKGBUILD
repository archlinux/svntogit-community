# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=1.5.0
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
sha512sums=('046c7f86947746bf54703b735142c254425f1b27307518302fcb3393598a0f0dde0509dda109cb174dfda617ec26033bc20b1d378a7df42335b71c0cb612361f')

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
