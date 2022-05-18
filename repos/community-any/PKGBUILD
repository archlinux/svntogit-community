# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.5.0
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/$pkgver.tar.gz")
sha512sums=('f46e1ac8b022a9aead975d6cda406d1a25ad19290cd64f1f179d6823d33013aeb4f3b42d2c90764a0607a8b9e67c3e287a565e7d4b07ddce63cafc5e988d7d2c')

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
