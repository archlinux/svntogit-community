# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.7.1
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/$pkgver.tar.gz")
sha512sums=('66708398ae3c4dcd97a6031feca6a1b7d1010a5ee605c5adce29a9cfabe67c5464eefb3812c66e2c32c3547240fdc7acac6eec25cc8dfb2d5255079c5e6b44b4')

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
