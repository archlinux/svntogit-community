# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Germán Osella Massa <gosella@gmail.com>

pkgname=python-more-itertools
pkgver=8.0.2
pkgrel=1
pkgdesc='More routines for operating on iterables, beyond itertools'
arch=('any')
url='https://github.com/erikrose/more-itertools'
#url='https://pypi.python.org/pypi/more-itertools'
license=('MIT')
depends=('python' 'python-six')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/m/more-itertools/more-itertools-$pkgver.tar.gz")
sha512sums=('c309bfd988efb702c25c241ca76379e0be07e1fdfb9d648c257760ac76872fd1aa77b321d94c2af9be8fb9a6709b4c60a9e0e9eb7450757ee74046bb5f9101b4')

package() {
  cd "$srcdir/more-itertools-$pkgver"
  python3 setup.py install --root="$pkgdir/" --optimize=0
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
