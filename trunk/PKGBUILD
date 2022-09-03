# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=markdown-it-py
pkgname=python-$_pkgname
pkgver=2.1.0
pkgrel=1
pkgdesc='Python port of markdown-it. Markdown parsing, done right!'
arch=('any')
url='https://github.com/executablebooks/markdown-it-py'
license=('MIT')
depends=('python-mdurl')
optdepends=('python-mdit_py_plugins: core plugins')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-regressions' 'python-pytest-benchmark' 'python-psutil' 'python-mdit_py_plugins' 'python-linkify-it-py')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('04e90538c8693f795aed2ed0a5bef4eaf0c12fac32cc0c2049c563e974b229940b9ceaea849ce86fa9804ccdd7be93145f3b6fc8d0774e96fafa0484368d0a88')

build() {
  cd $_pkgname-$pkgver

  python -m build
}

check() {
  cd $_pkgname-$pkgver

  python -m pytest
}

package() {
  cd $_pkgname-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
