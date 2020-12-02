# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: xantares

pkgname=python-snowballstemmer
pkgver=2.0.0
pkgrel=6
arch=('any')
pkgdesc="Snowball stemming library collection for Python"
url='https://snowballstem.org'
license=('BSD')
depends=('python')
optdepends=('python-pystemmer: for improved performance')
makedepends=('python-setuptools')
source=("https://pypi.python.org/packages/source/s/snowballstemmer/snowballstemmer-$pkgver.tar.gz")
md5sums=('c05ec4a897be3c953c8b8b844c4241d4')

build() {
  cd "$srcdir"/snowballstemmer-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/snowballstemmer-$pkgver/src
  PYTHONPATH=. python sample/testapp.py english "what's this"
}

package() {
  cd "$srcdir"/snowballstemmer-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/COPYING
}
