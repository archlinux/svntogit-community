# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-py3c
pkgver=1.4
pkgrel=2
pkgdesc="A Python 2/3 compatibility layer for C extensions"
url="https://github.com/encukou/py3c"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/encukou/py3c/archive/v$pkgver.tar.gz")
sha512sums=('db71db2c19a16ba5a430b676beb357faee5b67b161478932af13dd06be23b5505da85dbaf5b2447f95590fea55b833ee33fa19d3350ba3117f3364a9ab012ee6')

prepare() {
  cd py3c-$pkgver
  # Don't regenerate with broken path in "install" target
  sed -i 's/install: py3c.pc/install:/' Makefile
}

build() {
  cd py3c-$pkgver
  python setup.py build
  make prefix=/usr py3c.pc
}

check() {
  cd py3c-$pkgver
  make test-python
}

package() {
  cd py3c-$pkgver
  make prefix="$pkgdir"/usr install
  python setup.py install --root="$pkgdir" --optimize=1

  # Remove headers in broken location
  rm -r "$pkgdir"/usr/include/python*

  install -Dm644 LICENSE.MIT -t "$pkgdir"/usr/share/licenses/$pkgname/
}
