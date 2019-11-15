# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
_libname=${pkgname/python-/}
pkgver=2019.6.16
pkgrel=3
pkgdesc="Python package for providing Mozilla's CA Bundle"
arch=(any)
url="https://pypi.python.org/pypi/certifi"
license=('GPL')
depends=('python')
makedepends=('python-setuptools')
source=("https://pypi.io/packages/source/${_libname:0:1}/$_libname/$_libname-$pkgver.tar.gz")
sha512sums=('4641626bc5073cd0b3a520855ddef1007dcb42933baa7a3469856f936e725581042bcbd5b67e984ba9748e7faa62b9125cba7dc160dcc5db2eafe46461a29f5e')

build() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py build
}

package() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
