# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
_libname=${pkgname/python-/}
pkgver=2020.12.5
pkgrel=1
pkgdesc="Python package for providing Mozilla's CA Bundle"
arch=(any)
url="https://pypi.python.org/pypi/certifi"
license=('GPL')
depends=('python')
makedepends=('python-setuptools')
source=("https://pypi.io/packages/source/${_libname:0:1}/$_libname/$_libname-$pkgver.tar.gz")
sha512sums=('3425d98f19025e70d885458629071c8531271d93d1461fadea6afbaafc763881a42b3c05be391a938d84a0d1ab729c3ac5df4f3328e8ef63a7b56ead1445bddd')

build() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py build
}

package() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
