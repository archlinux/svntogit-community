# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.5.1
pkgrel=1
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pypa/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-flit-core' 'python-build'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser'
             'python-sphinx-argparse')
checkdepends=('python-pytest' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/$pkgver.tar.gz")
sha512sums=('0320c1795c98a593b5da46775465e26bdf8736f59835970517cb02f2756030a3744b9385a9342e8062362d0769d585ff6cce504fdf105e99d27d6ba40281842b')

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
