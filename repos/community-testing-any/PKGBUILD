# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=markdown-it-py
pkgname=python-$_pkgname
pkgver=2.2.0
pkgrel=3
pkgdesc='Python port of markdown-it. Markdown parsing, done right!'
arch=('any')
url='https://github.com/executablebooks/markdown-it-py'
license=('MIT')
depends=('python-mdurl')
optdepends=('python-mdit_py_plugins: core plugins')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-regressions' 'python-pytest-benchmark' 'python-psutil' 'python-mdit_py_plugins' 'python-linkify-it-py')
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz")
sha512sums=('84d6c15084bf33bdecdcbc8419322f2898bde20de6baeaee6c66c4e6ad9e47dfb8a14e2b1fcf71b8c42e7b61a7caed119919faf0faf6765aad85c186d91fe9d5')

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
