# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=1.6.0
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
sha512sums=('96f653348047d6aeeb6ebdac776c951509abebbba338893658d304b85263717757437427fc31a69799cd137ddf83052334befa50724e0b5ae2b54d7783d031a0')

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
