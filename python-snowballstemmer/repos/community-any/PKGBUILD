# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: xantares

pkgname=python-snowballstemmer
pkgver=2.1.0
pkgrel=1
arch=('any')
pkgdesc="Snowball stemming library collection for Python"
url='https://snowballstem.org'
license=('BSD')
depends=('python')
optdepends=('python-pystemmer: for improved performance')
makedepends=('python-setuptools')
source=("https://pypi.python.org/packages/source/s/snowballstemmer/snowballstemmer-$pkgver.tar.gz")
sha512sums=('e0550d3389074d7686d26397ff2289519cd8b26cf7090fe781d6407d1c2b95f912347d70cd25e02d6016c454ad6c5cf6d648e54ef87161328ac57bc1ceaf7826')

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
