# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Germán Osella Massa <gosella@gmail.com>

pkgname=python-more-itertools
pkgver=8.13.0
pkgrel=1
pkgdesc='More routines for operating on iterables, beyond itertools'
arch=('any')
url='https://github.com/erikrose/more-itertools'
#url='https://pypi.python.org/pypi/more-itertools'
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel' 'python-flit')
source=("https://files.pythonhosted.org/packages/source/m/more-itertools/more-itertools-$pkgver.tar.gz")
sha512sums=('2f3473cdd67ddcb2c658f60638b91a25c4ce9d9a92bbda5ca937dd4748857408bfe8dd9d4e699f53bd9f10d7b433db57e499bd28f184b8faa58b2004f2c92004')

build() {
  cd more-itertools-$pkgver
  python -m build --wheel --no-isolation
}

package() {
  cd more-itertools-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
