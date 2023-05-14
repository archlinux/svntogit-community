# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=sphinx-inline-tabs
pkgname=python-$_pkgname
pkgver=2023.04.21
pkgrel=1
pkgdesc='Add inline tabbed content to your Sphinx documentation'
arch=('any')
url='https://github.com/pradyunsg/sphinx-inline-tabs'
license=('MIT')
depends=('python-sphinx')
makedepends=('python-build' 'python-installer' 'python-flit-core')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('cad9ccdbf820c69b1f729d6c44ce34ec6005b5a72819f18aff0bf2a02aab66162c51f6a00119c95bddbea39363ce42ead502dc2526013785cb98e3b21965de7d')

build() {
  cd $_pkgname-$pkgver

  python -m build --wheel --no-isolation
}

package() {
  cd $_pkgname-$pkgver

  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
