# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.1.2
pkgrel=1
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools-scm' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest')
source=("https://github.com/jaraco/jaraco.context/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('bac276b2c5f3e9b3941c8ba48a87aec044591580c1d3ac9350dcaa79e5a421f56a58d8fffc4e0cb57cdcb63b2afffb33bf1e525f858316b084ff9c4c55df797f')

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
