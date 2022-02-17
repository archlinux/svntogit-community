# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.5.0
pkgrel=2
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pradyunsg/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-flit-core' 'python-build'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser'
             'python-sphinx-argparse')
checkdepends=('python-pytest' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/$pkgver.tar.gz")
sha256sums=('e993aa80138d7aa463f1950f013a884c7bad9b1148f083753351d97f3727dc4c')
sha512sums=('8731bbf8a51b1094dc87f84575eec07a650988bdeddf205d04cf80a5088eac0d8b2927022864f4011a9562fcaae9f511747e5672f94ec3cce1dccdfa833c4fce')

build() {
  cd $_pkgname-$pkgver

  python -m build -wn

  PYTHONPATH=src sphinx-build -b dirhtml -v docs docs/build/html
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src python -m installer --destdir="$pkgdir" dist/*.whl

  # remove windows entrypoint scripts executables
  rm "$pkgdir"/usr/lib/python*/site-packages/installer/_scripts/*.exe

  # install documentation
  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
