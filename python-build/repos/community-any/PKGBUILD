# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=build
pkgname=python-$_pkgname
pkgver=0.0.1
pkgrel=1
pkgdesc='A simple, correct PEP517 package builder'
arch=('any')
url='https://github.com/FFY00/python-build'
license=('GPL')
depends=('python-toml' 'python-pep517' 'python-packaging')
makedepends=('git' 'python-setuptools')
source=("git+$url#tag=$pkgver?signed")
validpgpkeys=('3DCE51D60930EBA47858BA4146F633CBB0EB4BF2') # Filipe Laíns (FFY00) <lains@archlinux.org>
sha512sums=('SKIP')

build() {
  cd $pkgname

  python setup.py build
}

package() {
  cd $pkgname

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

