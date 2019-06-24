# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgbase=python-certifi
pkgname=('python-certifi' 'python2-certifi')
_libname=${pkgbase/python-/}
pkgver=2019.6.16
pkgrel=1
pkgdesc="Python package for providing Mozilla's CA Bundle"
arch=(any)
url="https://pypi.python.org/pypi/certifi"
license=('GPL')
makedepends=('python-setuptools' 'python2-setuptools')
source=("https://pypi.io/packages/source/${_libname:0:1}/$_libname/$_libname-$pkgver.tar.gz")
sha512sums=('4641626bc5073cd0b3a520855ddef1007dcb42933baa7a3469856f936e725581042bcbd5b67e984ba9748e7faa62b9125cba7dc160dcc5db2eafe46461a29f5e')

prepare() {
  cp -a $_libname-$pkgver{,-py2}

  cd $_libname-$pkgver-py2
  sed -i '1s|python$|python2|' certifi/core.py
}

build() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py build

  cd "$srcdir/$_libname-$pkgver-py2"
  python2 setup.py build
}

package_python-certifi() {
  depends=('python')

  cd "$srcdir/$_libname-$pkgver"
  python setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-certifi() {
  depends=('python2')

  cd "$srcdir/$_libname-$pkgver-py2"
  python2 setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
