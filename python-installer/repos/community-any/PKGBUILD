# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.6.0
pkgrel=1
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pypa/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-flit-core' 'python-build'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser'
             'python-sphinx-argparse')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/$pkgver.tar.gz")
sha512sums=('0952bbf245359d6f660f98e59096ed3d57facb5bad0e9715fe525bd52f50cce198b481811d2ba4d204776f7ae9bec9c3431ae044d6ef9a8db8d873c170cf13fb')

build() {
  cd $_pkgname-$pkgver

  python -m build -wn --skip-dependency-check

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
