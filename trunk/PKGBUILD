# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Blackleg <blacklg@openaliasbox.org>
# Contributor: Nidhogg
# Contributor: juantascon

pkgname=python-peewee
pkgver=3.16.2
pkgrel=2
pkgdesc="a little orm"
url="https://github.com/coleifer/peewee/"
arch=('x86_64')
license=('MIT')
depends=('python' 'sqlite')
optdepends=('python-psycopg2: for PostgreSQL database support'
            'python-pymysql: for MySQL database support')
makedepends=('python-build' 'python-installer' 'cython' 'python-setuptools' 'python-wheel')
checkdepends=('python-apsw' 'python-flask' 'python-psycopg2')
source=("$pkgname-$pkgver.tar.gz::https://github.com/coleifer/peewee/archive/$pkgver.tar.gz")
sha512sums=('7e507d9f2ace45c5ec482d657e7722812fae10eea9a23b12caf2611d3739bc6dc70800f21d606d5e854e3209dd6d2ff73b93f004515f6549c3bbc423bce650d8')

build() {
  cd peewee-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd peewee-$pkgver
  python runtests.py
}

package() {
  cd peewee-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
