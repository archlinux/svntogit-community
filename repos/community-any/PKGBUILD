# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-filelock
pkgname=(python-filelock python2-filelock)
pkgver=3.0.10
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/v$pkgver.tar.gz")
sha512sums=('1fa4594eaba6689ea61149a60a71e86007297614a1c22dc6c94b4774520d396ff8ad03076dfdbb2ce49d2b6e42c374af065a115c167d81cf6107918abfbe52ef')

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
