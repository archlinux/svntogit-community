# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-autocommand
pkgver=2.2.2
pkgrel=4
pkgdesc="A library to create a command-line program from a function"
url="https://github.com/Lucretiel/autocommand"
license=('LGPL')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://github.com/Lucretiel/autocommand/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('5ed109db16a0e309ed5107b26db0b70ed8669d73817e82eb5a219650d29f53785aa1f9471b2ac71d21dbffc9f0a13ea0fdf69e63ab534fd84407a1d6741cf5b5')

build() {
  cd autocommand-$pkgver
  python setup.py build
}

check() {
  cd autocommand-$pkgver
  PYTHONPATH="$PWD"/build/lib pytest
}

package() {
  cd autocommand-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
