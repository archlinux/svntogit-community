# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-filelock
pkgver=3.7.0
pkgrel=1
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python-setuptools-scm')
checkdepends=('python-pytest' 'python-pytest-timeout')
source=("$pkgname-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/$pkgver.tar.gz")
sha512sums=('1b01a25a1ec194be1727a7245d6bada3a5f6e38bc16c0c78793ec0cf3dcdee6cc6b5c04fc74ae3687afd354379c73e189f7f3a8964853b8533a489ed2a0c6a04')

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
