# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pluggy
pkgver=0.13.1
pkgrel=8
pkgdesc="Plugin and hook calling mechanisms for python"
arch=('any')
url="https://github.com/pytest-dev/pluggy"
license=('MIT')
depends=('python-importlib-metadata')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pytest-dev/pluggy/archive/$pkgver.tar.gz")
sha512sums=('3269f7ad7801a70ba8aa3182c568f70e2ee88a90b6f6335be631f9737dd42fac3fb1b27c5b6fe6422de128ddcc58736f0c41ed60b7c0177126dd676b98ece301')

prepare() {
  export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver
}

build() {
  cd "$srcdir"/pluggy-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/pluggy-$pkgver
  python setup.py pytest
}

package() {
  cd pluggy-$pkgver
  python setup.py install -O1 --root "$pkgdir"

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
