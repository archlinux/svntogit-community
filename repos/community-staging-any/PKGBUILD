# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
_libname=${pkgname/python-/}
pkgver=2020.6.20
pkgrel=3
pkgdesc="Python package for providing Mozilla's CA Bundle"
arch=(any)
url="https://pypi.python.org/pypi/certifi"
license=('GPL')
depends=('python')
makedepends=('python-setuptools')
source=("https://pypi.io/packages/source/${_libname:0:1}/$_libname/$_libname-$pkgver.tar.gz")
sha512sums=('a0f22aec563636c270607ce1a27c9996b09f30cf7601b4ed7d7bc20572c411032134c92645f26962331936035cb7016d79b36680c71b7521e00dd0288827a0dc')

build() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py build
}

package() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
