# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgbase=python-colorama
pkgname=('python-colorama' 'python2-colorama')
pkgver=0.4.3
pkgrel=1
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-mock' 'python2-mock')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('ab41a2f95fe75de0b280c174c6166b86645e5cc675dcedf784fe15170aae630e831370527c9490342b77c7d088a023a48428a519b52ad1c70be58904742a94c8')

prepare() {
  cp -a colorama-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/colorama-$pkgver
  python setup.py build

  cd "$srcdir"/colorama-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/colorama-$pkgver
  python -m unittest discover -p *_test.py || warning "Tests failed"

  cd "$srcdir"/colorama-$pkgver-py2
  python2 -m unittest discover -p *_test.py || warning "Tests failed"
}

package_python-colorama() {
  depends=('python')

  cd colorama-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}

package_python2-colorama() {
  depends=('python2')

  cd colorama-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}

# vim:set ts=2 sw=2 et:
