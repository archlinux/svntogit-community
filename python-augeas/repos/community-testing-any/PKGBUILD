# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>

pkgname=python-augeas
pkgver=1.1.0
pkgrel=6
pkgdesc="Python bindings for Augeas"
arch=('any')
license=('LGPL')
url="http://augeas.net"
depends=('augeas' 'python-cffi')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/p/python-augeas/python-augeas-$pkgver.tar.gz")
sha512sums=('34e4e98219b9146ef843d94c2e854e951a9b7e81409e603e77e7defdbb8765c013a2c869a4f5db2244352ca35656e18667a0210dd24099cb3e4552a04b23aef8')

build() {
  cd python-augeas-$pkgver
  python setup.py build
}

check() {
  cd python-augeas-$pkgver
  PYTHONPATH="$PWD/build/lib:$PYTHONPATH" make check
}

package() {
  cd python-augeas-$pkgver
  python setup.py install --skip-build -O1 --root="$pkgdir"
}
