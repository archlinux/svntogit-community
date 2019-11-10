# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-deprecated
pkgname=(python-deprecated python2-deprecated)
pkgver=1.2.6
pkgrel=3
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python-wrapt' 'python2-wrapt')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('fcef322c6d9c317081dae365d469d4b26b0d23d8290e7aa0ca18592fb098ae7f535cb5e898cc81e5c734e7e211c847cdd9d5430c1999a4b9612f30934243ee9e')

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
