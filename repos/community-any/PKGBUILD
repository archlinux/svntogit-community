
pkgbase=python-lockfile
pkgname=(python-lockfile)
pkgver=0.12.2
pkgrel=9
pkgdesc='Platform-independent file locking module'
arch=(any)
url='https://github.com/openstack/pylockfile'
license=(MIT)
depends=(python)
makedepends=(python-setuptools python-pbr)
checkdepends=(python-nose)
source=(https://files.pythonhosted.org/packages/source/l/lockfile/lockfile-$pkgver.tar.gz)
sha1sums=('c2ac46e48585e5f8f8d57ccc55ca83faa8b53b86')

prepare() {
  cp -a lockfile-$pkgver{,-py2}
}

build() {
  cd "$srcdir/lockfile-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/lockfile-$pkgver"
  nosetests
}

package() {
  cd "$srcdir/lockfile-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
