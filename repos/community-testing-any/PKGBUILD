# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-whatever
pkgver=0.7
_commit=7f2cab8e8dfe50e0696b149c68b1c3fff7b70094
pkgrel=3
pkgdesc='Easy way to make anonymous functions by partial application of operators'
arch=('any')
license=('BSD')
url='https://github.com/Suor/whatever'
depends=('python')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pytest')
source=("git+https://github.com/Suor/whatever.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd whatever
  python setup.py build
}

check() {
  cd whatever
  pytest
}

package() {
  cd whatever
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
