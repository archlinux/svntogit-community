# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: xantares

pkgname=python-snowballstemmer
pkgver=2.2.0
pkgrel=5
arch=('any')
pkgdesc="Snowball stemming library collection for Python"
url='https://snowballstem.org'
license=('BSD')
depends=('python')
optdepends=('python-pystemmer: for improved performance')
makedepends=('python-setuptools')
source=("https://pypi.python.org/packages/source/s/snowballstemmer/snowballstemmer-$pkgver.tar.gz")
sha512sums=('f1dee83e06fc79ffb250892fe62c75e3393b9af07fbf7cde413e6391870aa74934302771239dea5c9bc89806684f95059b00c9ffbcf7340375c9dd8f1216cd37')

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
