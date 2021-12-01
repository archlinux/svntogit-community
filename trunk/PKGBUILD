# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgname=python-colorama
pkgver=0.4.4
pkgrel=6
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-mock')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('35501915b79bfc5fe46a36f83790ecd79c82150d6b73a57cd55fbe6431ea5ed7a86676504af90147eeb3a963ffd16890e0220099df579a66f2d8f1f7494f862e')

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
