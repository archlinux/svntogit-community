# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=sphinx-inline-tabs
pkgname=python-$_pkgname
pkgver=2022.01.02.beta11
pkgrel=2
pkgdesc='Add inline tabbed content to your Sphinx documentation'
arch=('any')
url='https://github.com/pradyunsg/sphinx-inline-tabs'
license=('MIT')
depends=('python-sphinx')
makedepends=('python-build' 'python-installer' 'python-flit-core')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('353e9168cd8e2e3ad395f4f2c7f94f40def3445f2d5e45f1610b463fa718b4b15c1070ec95930d769e6f28bdb319dbc447aac0801ddb12c31899a160a8abd1a9')

build() {
  cd $_pkgname-$pkgver

  python -m build --wheel --no-isolation
}

package() {
  cd $_pkgname-$pkgver

  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
