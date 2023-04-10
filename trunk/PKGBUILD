# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=mdurl
pkgname=python-$_pkgname
pkgver=0.1.2
pkgrel=4
pkgdesc='URL utilities for markdown-it'
arch=('any')
url='https://github.com/executablebooks/mdurl'
license=('MIT')
depends=('python-uc-micro-py')
makedepends=('python-build' 'python-installer' 'python-flit-core' 'python-wheel')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('e301ca3ab6d80df1ad28b9c2725d66b6e6cf139d93e5f7fd2a70333678616a3f6db64f15250972eee3cd1cf1eaff6ec587415629e6802dcf07995edff6865ff2')

build() {
  cd $_pkgname-$pkgver

  python -m build -nw
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src python -m pytest
}

package() {
  cd $_pkgname-$pkgver

  python -m installer -d "$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
