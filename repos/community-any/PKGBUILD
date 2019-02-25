# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pluggy
pkgname=(python-pluggy python2-pluggy)
pkgver=0.9.0
pkgrel=1
pkgdesc="Plugin and hook calling mechanisms for python"
arch=('any')
url="https://www.pluggypayments.com/docs/python"
license=('MIT')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/pytest-dev/pluggy/archive/$pkgver.tar.gz")
sha512sums=('e4adcd4de9758476a43c338baf7d13b0a1380739d7c6cc593537a3ec63a6491250adf0f33183e323f50695d9d0191a7d3378b1d36df44f9355625624ef1c4551')

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
