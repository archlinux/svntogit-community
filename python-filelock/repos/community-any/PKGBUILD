# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-filelock
pkgname=(python-filelock python2-filelock)
pkgver=3.0.9
_commit=b71c3a494b1a9a84ddaa4a4d43bfd985a01e81e7
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgbase-$_commit.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/$_commit.tar.gz")
sha512sums=('bf2c3a27488e4e0b0469599c5037658482b27eee08ef1844de5419865a67f01966b72f1f463ce7418660901c991ad06740a90f332db0b2d3d62967f0f270aba9')

prepare() {
  mv py-filelock-{$_commit,$pkgver}
}

build() {
  cd py-filelock-$pkgver
  python setup.py build
  python2 setup.py build
}

check() {
  cd py-filelock-$pkgver
  pytest test.py
  pytest2 test.py
}

package_python-filelock() {
  depends=('python')

  cd py-filelock-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}

package_python2-filelock() {
  depends=('python2')

  cd py-filelock-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
