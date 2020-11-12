# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=build
pkgname=python-$_pkgname
pkgver=0.1.0
pkgrel=2
pkgdesc='A simple, correct PEP517 package builder'
arch=('any')
url='https://github.com/pypa/build'
license=('MIT')
depends=('python-toml' 'python-pep517' 'python-packaging')
makedepends=('git' 'python-setuptools'
             'python-sphinx' 'python-sphinxcontrib-autoprogram' 'python-sphinx-autodoc-typehints' 'python-sphinx-furo')
source=("git+$url#tag=$pkgver?signed")
validpgpkeys=('3DCE51D60930EBA47858BA4146F633CBB0EB4BF2') # Filipe Laíns (FFY00) <lains@archlinux.org>
sha512sums=('SKIP')

build() {
  cd $_pkgname

  python setup.py build

  cd docs

  PYTHONPATH=../src sphinx-build -b dirhtml -v source build/html
}

package() {
  cd $_pkgname

  python setup.py install --root="$pkgdir" --skip-build
  python -m compileall --invalidation-mode=checked-hash "$pkgdir"

  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
