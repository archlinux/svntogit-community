# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=build
pkgname=python-$_pkgname
pkgver=0.0.4
pkgrel=1
pkgdesc='A simple, correct PEP517 package builder'
arch=('any')
url='https://github.com/FFY00/python-build'
license=('GPL')
depends=('python-toml' 'python-pep517' 'python-packaging')
makedepends=('git' 'python-setuptools'
             'python-sphinx' 'python-sphinxcontrib-autoprogram' 'python-sphinx-autodoc-typehints' 'python-pallets-sphinx-themes')
source=("git+$url#tag=$pkgver?signed")
validpgpkeys=('3DCE51D60930EBA47858BA4146F633CBB0EB4BF2') # Filipe Laíns (FFY00) <lains@archlinux.org>
sha512sums=('SKIP')

build() {
  cd $pkgname

  python setup.py build

  cd docs

  PYTHONPATH=.. make
}

package() {
  cd $pkgname

  python setup.py install --root="$pkgdir" --skip-build
  python -m compileall --invalidation-mode=checked-hash "$pkgdir"

  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
}

