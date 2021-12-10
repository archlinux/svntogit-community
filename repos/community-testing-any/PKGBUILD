# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=sphinx-theme-builder
pkgname=python-$_pkgname
pkgver=0.2.0a12
pkgrel=2
pkgdesc='Python build backend for Sphinx themes'
arch=('any')
url='https://github.com/pradyunsg/sphinx-theme-builder'
license=('BSD')
depends=('python' 'python-packaging' 'python-rich' 'python-tomli' 'python-nodeenv' 'python-setuptools' 'python-pep621')
optdepends=('python-build: CLI'
            'python-click: CLI'
            'python-sphinx-autobuild: CLI')
makedepends=('python-setuptools' 'python-dephell')
checkdepends=('python-pytest' 'python-build' 'python-click' 'python-sphinx-autobuild')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz")
sha512sums=('58aa883d200ac26f357b1d1b0df500b0a4a05cbc143e97532eb32e5a422f2db2d33d6bb27445964f6833e2c9538115e85517245b16fd1cb6f538ab39122bc5b3')

prepare() {
  cd $_pkgname-$pkgver

  dephell deps convert --from pyproject.toml --to setup.py
}

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
