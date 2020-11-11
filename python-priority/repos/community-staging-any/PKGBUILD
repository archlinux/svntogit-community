# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-priority
pkgver=1.3.0
pkgrel=7
pkgdesc='A pure-Python implementation of the HTTP/2 priority tree'
arch=('any')
license=('MIT')
url='https://github.com/python-hyper/priority'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-hypothesis')
source=("$pkgname-$pkgver.tar.gz::https://github.com/python-hyper/priority/archive/v$pkgver.tar.gz")
sha512sums=('bd60db8e1f524a2c445227576d53c70dbf5764e9ecb0e75d320e3652941f9e915f9d130815a781a8d4e50c4c3f68e05c9458225926e80d588e210037a1c6ed5f')

build() {
  cd priority-$pkgver
  python setup.py build
}

check() {
  cd priority-$pkgver
  python setup.py pytest
}

package() {
  cd priority-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
