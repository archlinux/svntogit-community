# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-autoprogram
pkgver=0.1.8
_commit=b6df97b08e1c28684911f7704422da074d4c4e27
pkgrel=2
pkgdesc="Documenting CLI programs"
url="https://github.com/sphinx-contrib/autoprogram"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'python-six')
makedepends=('git' 'python-setuptools')
source=("git+https://github.com/sphinx-contrib/autoprogram.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd autoprogram
  python setup.py build
}

check() {
  cd autoprogram
  python setup.py test
}

package() {
  cd autoprogram
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
