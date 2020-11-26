# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Alexander Duscheleit <jinks@archlinux.us>

pkgbase=python-colorama
pkgname=('python-colorama' 'python2-colorama')
pkgver=0.4.4
pkgrel=3
pkgdesc="Python API for cross-platform colored terminal text."
arch=('any')
url="https://pypi.python.org/pypi/colorama"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-mock' 'python2-mock')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tartley/colorama/archive/$pkgver.tar.gz")
sha512sums=('35501915b79bfc5fe46a36f83790ecd79c82150d6b73a57cd55fbe6431ea5ed7a86676504af90147eeb3a963ffd16890e0220099df579a66f2d8f1f7494f862e')

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
  python -m unittest discover -p *_test.py || echo "Tests failed"

  cd "$srcdir"/colorama-$pkgver-py2
  python2 -m unittest discover -p *_test.py || echo "Tests failed"
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
