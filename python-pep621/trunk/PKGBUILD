# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=python-pep621
pkgver=0.4.0
pkgrel=3
pkgdesc='PEP 621 metadata parsing'
arch=('any')
url='https://github.com/FFY00/python-pep621'
license=('MIT')
depends=('python-packaging')
makedepends=('git' 'python-setuptools' 'python-sphinx' 'python-sphinx-autodoc-typehints' 'python-sphinx-furo')
checkdepends=('python-pytest' 'python-tomli')
source=("git+$url#tag=$pkgver?signed")
validpgpkeys=('3DCE51D60930EBA47858BA4146F633CBB0EB4BF2') # Filipe Laíns (FFY00) <lains@archlinux.org>
sha512sums=('SKIP')

prepare() {
  echo 'from setuptools import setup; setup()' >$pkgname/setup.py
}

build() {
  cd $pkgname

  python setup.py build

  PYTHONPATH=. sphinx-build -b dirhtml -v docs docs/build/html
}

check() {
  cd $pkgname

  python -m pytest
}

package() {
  cd $pkgname

  python setup.py install --root="$pkgdir" --skip-build
  python -m compileall --invalidation-mode=checked-hash "$pkgdir"

  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
