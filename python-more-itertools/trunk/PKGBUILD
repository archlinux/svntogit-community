# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Germán Osella Massa <gosella@gmail.com>

pkgname=python-more-itertools
pkgver=8.12.0
pkgrel=2
pkgdesc='More routines for operating on iterables, beyond itertools'
arch=('any')
url='https://github.com/erikrose/more-itertools'
#url='https://pypi.python.org/pypi/more-itertools'
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
source=("https://files.pythonhosted.org/packages/source/m/more-itertools/more-itertools-$pkgver.tar.gz")
sha512sums=('73759f05d178bd6fe98cadac401707faf90a4f7b456c4aac3f0b3f6c13a2284600971e0b271f1768cacd3ae9b69848404f85432199ca51b8160fbe67045dfd17')

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
