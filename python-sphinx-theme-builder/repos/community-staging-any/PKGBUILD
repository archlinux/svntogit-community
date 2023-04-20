# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=sphinx-theme-builder
pkgname=python-$_pkgname
pkgver=0.2.0b2
pkgrel=2
pkgdesc='Python build backend for Sphinx themes'
arch=('any')
url='https://github.com/pradyunsg/sphinx-theme-builder'
license=('BSD')
depends=('python' 'python-packaging' 'python-rich' 'python-tomli' 'python-nodeenv' 'python-setuptools' 'python-pep621' 'python-pyproject-metadata')
optdepends=('python-build: CLI'
            'python-click: CLI'
            'python-sphinx-autobuild: CLI')
makedepends=('python-build' 'python-installer' 'python-flit-core')
checkdepends=('python-pytest' 'python-click' 'python-sphinx-autobuild')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('9900812cbb91a2fae666c010caef0fc2d250ff7ef8ae7b0105c72cee678e4be49784530c49c43d0260e22882ca7b89d4dd83da0c5a59cf3f944647f84e9fd6bf')

build() {
  cd $_pkgname-$pkgver

  python -m build --wheel --no-isolation
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname-$pkgver

  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
