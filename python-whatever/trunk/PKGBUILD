# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-whatever
pkgver=0.5
pkgrel=3
pkgdesc='Easy way to make anonymous functions by partial application of operators'
arch=('any')
license=('BSD')
url='https://github.com/Suor/whatever'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/whatever/archive/$pkgver.tar.gz")
sha512sums=('eb3f0b9bc63197c1bfdd135a46a597e2f5d6131900910f266c984c1afd901d6cbc8c8ee62397e9af8393bf34beff068dc0007e8b016e70f275e019420f18f6e1')

prepare() {
  sed -i -e 's/(1, 0, 1)/(1, 0, 0, 1)/' -e 's/(self._arity, 0, self._arity)/(self._arity, 0, 0, self._arity)/' whatever-$pkgver/whatever.py
}

build() {
  cd whatever-$pkgver
  python setup.py build
}

check() {
  cd whatever-$pkgver
  python setup.py pytest
}

package() {
  cd whatever-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
