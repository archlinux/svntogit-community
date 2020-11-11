# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-filelock
pkgname=(python-filelock python2-filelock)
pkgver=3.0.12
pkgrel=5
pkgdesc="A platform independent file lock"
url="https://github.com/benediktschmitt/py-filelock"
license=('custom:Unlicense')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/benediktschmitt/py-filelock/archive/v$pkgver.tar.gz")
sha512sums=('0f30b54b9de2540f023855effcc582b18fedcee6681f21e1733f1b60dbd39eb148e3830bc798a44c5e8c22e7ea8ca26b6d4547fae79dacc78c62b819a3d84683')

build() {
  cd py-filelock-$pkgver
  python setup.py build
  python2 setup.py build
}

check() {
  cd py-filelock-$pkgver
  pytest test.py
  pytest2 test.py
}

package_python-filelock() {
  depends=('python')

  cd py-filelock-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}

package_python2-filelock() {
  depends=('python2')

  cd py-filelock-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
