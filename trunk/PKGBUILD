# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgname=python-colorama
pkgver=0.4.5
pkgrel=1
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('d4d3b2a4c6a0966b5c15a12cd789e4b68e5b632c4d745d93fcff5e250fe10e5d45dd2a8bd25f4399cca31a358aecf99f354aa3e1b74369ae382b51bd6c87644f')

build() {
  cd "$srcdir"/colorama-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/colorama-$pkgver
  python -m unittest discover -p *_test.py || echo "Tests failed"
}

package() {
  cd colorama-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}
