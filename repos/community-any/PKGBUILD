# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.6.0
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/$pkgver.tar.gz")
sha512sums=('f55ad90d79e90eb5a915afffecc632566456604a62b89fb13304c5812e05a34c508c863e76246a254acd98f55930d3179b0908a06d1e5a203d578a826a048ae2')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd py-filelock-$pkgver
  python setup.py build
}

check() {
  cd py-filelock-$pkgver
  PYTHONPATH=src pytest tests
}

package() {
  cd py-filelock-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
