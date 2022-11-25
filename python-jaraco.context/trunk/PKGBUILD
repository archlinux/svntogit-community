# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.2.0
pkgrel=1
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
source=("https://github.com/jaraco/jaraco.context/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('3e4dcff86c02e4a297c3e26180c07a5c58375713f878c490f5908ef373f1126ea353ca3009befee0233269570f260476182833310f8437f37d58a58be1aaf480')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd jaraco.context-$pkgver
  python -m build -wn
}

check() {
  cd jaraco.context-$pkgver
  python -m pytest
}

package() {
  cd jaraco.context-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
