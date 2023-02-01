# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.2.1
_commit=7e22446a66f13140c0cfc7df3f36c162f11f3b5a
pkgrel=1
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
