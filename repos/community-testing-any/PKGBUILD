# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pluggy
pkgname=(python-pluggy python2-pluggy)
pkgver=0.11.0
pkgrel=1
pkgdesc="Plugin and hook calling mechanisms for python"
arch=('any')
url="https://www.pluggypayments.com/docs/python"
license=('MIT')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pluggy/archive/$pkgver.tar.gz")
sha512sums=('e63327ce02fe0b88ceb169c5df787fcf10d338069b18154219c2541635eb6653b33e7a982bf265b94e5b2c9bc98d5960e0da354a59f6a6287cfe009c6a1f8eb1')

prepare() {
  cp -a pluggy-$pkgver{,-py2}

  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver
}

build() {
  cd "$srcdir"/pluggy-$pkgver
  python setup.py build

  cd "$srcdir"/pluggy-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/pluggy-$pkgver
  python setup.py pytest

  cd "$srcdir"/pluggy-$pkgver-py2
  python2 setup.py pytest
}

package_python-pluggy() {
  depends=('python')

  cd pluggy-$pkgver
  python setup.py install -O1 --root "$pkgdir"

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-pluggy() {
  depends=('python2')

  cd pluggy-$pkgver-py2
  python2 setup.py install -O1 --root "$pkgdir"

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
