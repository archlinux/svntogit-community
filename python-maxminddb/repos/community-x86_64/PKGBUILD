# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-maxminddb
pkgver=2.3.0
_testdatacommit=e3764a229ff98541884a3cd4bd7dc95f4ae5d466
pkgrel=1
pkgdesc="Reader for the MaxMind DB format"
url="https://github.com/maxmind/MaxMind-DB-Reader-python"
license=('Apache')
arch=('x86_64')
depends=('python' 'libmaxminddb')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://github.com/maxmind/MaxMind-DB-Reader-python/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
        https://github.com/maxmind/MaxMind-DB/archive/$_testdatacommit.tar.gz)
sha512sums=('6b039e41e7d4b782d92f321a39f79c39c9a014528fe60a2b6a598e30c50afd33b08d49f94fb77da6d3174e93d71b521e2b7c5f9071ea2b5f90f350cf7d8f558d'
            '618bef60b69492aecd06467428e36d7a10f2aa846e7afd507b6eac1f3a6ceceeb14ed95654b629c9d2638634a5184658236b644edccc99ae2d24e35d9d1f6db9')

prepare() {
  cd MaxMind-DB-Reader-python-$pkgver
  rmdir tests/data
  ln -s "$srcdir"/MaxMind-DB-$_testdatacommit tests/data
}

build() {
  cd MaxMind-DB-Reader-python-$pkgver
  python setup.py build
}

check() {
  cd MaxMind-DB-Reader-python-$pkgver
  PYTHONPATH="build/lib.linux-$CARCH-cpython-311" pytest
}

package() {
  cd MaxMind-DB-Reader-python-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
