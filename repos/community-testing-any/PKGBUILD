# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: xantares

pkgbase=python-snowballstemmer
pkgname=('python-snowballstemmer' 'python2-snowballstemmer')
pkgver=2.0.0
pkgrel=3
arch=('any')
pkgdesc="Snowball stemming library collection for Python"
url='https://snowballstem.org'
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools')
source=("https://pypi.python.org/packages/source/s/snowballstemmer/snowballstemmer-$pkgver.tar.gz")
md5sums=('c05ec4a897be3c953c8b8b844c4241d4')

prepare() {
  cp -a snowballstemmer-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/snowballstemmer-$pkgver
  python setup.py build

  cd "$srcdir"/snowballstemmer-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/snowballstemmer-$pkgver/src
  PYTHONPATH=. python sample/testapp.py english "what's this"

  cd "$srcdir"/snowballstemmer-$pkgver-py2/src
  PYTHONPATH=. python2 sample/testapp.py english "what's this"
}

package_python-snowballstemmer() {
  depends=('python')
  optdepends=('python-pystemmer: for improved performance')

  cd "$srcdir"/snowballstemmer-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/COPYING
}

package_python2-snowballstemmer() {
  depends=('python2')
  optdepends=('python2-pystemmer: for improved performance')

  cd "$srcdir"/snowballstemmer-$pkgver-py2 
  python2 setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 COPYING "$pkgdir"/usr/share/licenses/$pkgname/COPYING
}
