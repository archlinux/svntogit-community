# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.2.0
_commit=5bf0042ef434aa8924a771a405ae29e4c0110c1e
pkgrel=2
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('git' 'python-setuptools-scm' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
source=("git+https://github.com/jaraco/jaraco.context.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd jaraco.context
  python -m build -wn
}

check() {
  cd jaraco.context
  python -m pytest
}

package() {
  cd jaraco.context
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
