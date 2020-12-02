# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=2.0.0
pkgrel=3
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python2-contextlib2'
             'python2-pathlib2' 'python2-configparser' 'python-zipp' 'python2-zipp')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python-importlib_resources' 'python2-importlib_resources' 'python-wheel'
              'python2-wheel' 'python-pyfakefs' 'python-tests')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/v$pkgver/importlib_metadata-v$pkgver.tar.bz2")
sha512sums=('f424973dca95dbbfcbddd21b0ce26873b6e732d93722789efe4a6f2367caa21cf18a22dc7ea089167d98568ecbbe2e0e3fff1155017bf2d9d50fc3775024cb37')

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
