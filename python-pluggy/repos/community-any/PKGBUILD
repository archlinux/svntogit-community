# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pluggy
pkgver=1.0.0
pkgrel=1
pkgdesc="Plugin and hook calling mechanisms for python"
arch=('any')
url="https://github.com/pytest-dev/pluggy"
license=('MIT')
depends=('python')
makedepends=('python-setuptools-scm')
checkdepends=('python-pytest')
source=("https://github.com/pytest-dev/pluggy/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('88f1180d2607115d6516cba07fa7c1f0e284d1e16fb7ed42c4a05d5d2b0dc1419d2bdbdadc34e2eb7f6b0cc9fc97715c6b184542c01f6bc33242a872c46d7903')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd pluggy-$pkgver
  python setup.py build
}

check() {
  cd pluggy-$pkgver
  PYTHONPATH="$PWD"/src pytest
}

package() {
  cd pluggy-$pkgver
  python setup.py install -O1 --root "$pkgdir"
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
