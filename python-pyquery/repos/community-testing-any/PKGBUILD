# Maintainer : Felix Yan <felixonmars@archlinux.org>
# Contributor: speps <speps at aur dot archlinux dot org>
# Contributor: Arnau Sanchez <tokland {at} gmail {dot} com>

pkgname=python-pyquery
pkgver=2.0.0
pkgrel=3
pkgdesc="A jquery-like library for python."
arch=('any')
url="https://github.com/gawel/pyquery/"
license=('BSD')
depends=('python-lxml' 'python-cssselect')
optdepends=('python-webob: query wsgi app')
makedepends=('python-setuptools')
checkdepends=('python-requests' 'python-webob' 'python-pytest' 'python-webtest')
source=("https://github.com/gawel/pyquery/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('0c44ca00ee30922e72aff23764d4a6a8ab9f4df684de77703b69b87af4b461ee2338ef5fb134dce280926e2575b976a1b86d16b1234e13fc450811e4874a34e9')

build() {
  cd pyquery-$pkgver
  python setup.py build
}

check() {
  cd pyquery-$pkgver
  pytest
}

package() {
  cd pyquery-$pkgver
  python setup.py install -O1 --root="$pkgdir"
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
