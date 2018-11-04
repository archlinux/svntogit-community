# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-deprecated
pkgname=(python-deprecated python2-deprecated)
pkgver=1.2.4
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python-wrapt' 'python2-wrapt')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('20531256f86789f9f52ed9e9db2b61bf253f888728754bcb654b6c049532f29295a6dd44aaad1f21fd17c072515af9b1da55586b0cdb25da620dd1788191d46c')

prepare() {
  cp -a deprecated-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py build

  cd "$srcdir"/deprecated-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py pytest

  cd "$srcdir"/deprecated-$pkgver-py2
  python2 setup.py pytest
}

package_python-deprecated() {
  depends=('python-wrapt')

  cd deprecated-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}

package_python2-deprecated() {
  depends=('python2-wrapt')

  cd deprecated-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
