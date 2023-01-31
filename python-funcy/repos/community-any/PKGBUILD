# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.18
_commit=416c187374a86b27ebd7ea882bb38764390e46ae
pkgrel=1
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pytest' 'python-whatever')
source=("git+https://github.com/Suor/funcy.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd funcy
  python setup.py build
}

check() {
  cd funcy
  pytest
}

package() {
  cd funcy
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
