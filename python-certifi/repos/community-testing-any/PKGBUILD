# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: William J Bowman <bluephoenix47@gmail.com>

pkgname=python-certifi
_libname=${pkgname/python-/}
pkgver=2021.10.8
pkgrel=3
pkgdesc="Python package for providing Mozilla's CA Bundle"
arch=(any)
url="https://pypi.python.org/pypi/certifi"
license=('GPL')
depends=('python')
makedepends=('python-setuptools')
source=("https://pypi.io/packages/source/${_libname:0:1}/$_libname/$_libname-$pkgver.tar.gz")
sha512sums=('06dc41a471f16f6c52751854e82fb42011c9388651cff55761298b86ba437d431e6325ab039ef330f2b2c5f69f5ba43dc468e7ca3df205a8bb31468f43711fbe')

build() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py build
}

package() {
  cd "$srcdir/$_libname-$pkgver"
  python setup.py install --skip-build -O1 --root="$pkgdir"
  install -m0644 -D "LICENSE" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
