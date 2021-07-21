# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Germán Osella Massa <gosella@gmail.com>

pkgname=python-more-itertools
pkgver=8.8.0
pkgrel=1
pkgdesc='More routines for operating on iterables, beyond itertools'
arch=('any')
url='https://github.com/erikrose/more-itertools'
#url='https://pypi.python.org/pypi/more-itertools'
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/m/more-itertools/more-itertools-$pkgver.tar.gz")
sha512sums=('c6efec614a10a2fc72a4bbb7c62ac586e5dd28e04582768e0b3749cbd8307df0b4a609637d427d9c4940874e2aed1432094c09ac249e16a20dc6a09723172f06')

package() {
  cd "$srcdir/more-itertools-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=0
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
