# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-deprecated
pkgname=(python-deprecated python2-deprecated)
pkgver=1.2.5
pkgrel=1
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools' 'python-wrapt' 'python2-wrapt')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz")
sha512sums=('3a16b5d4f2475788ce919c327b668bb8852dab88adfa959826c9b68ccbfba3207a1c60ca164edacde8a756bd3895225af944a51eebde1230a93a973145231234')

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
