# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.2.3
pkgrel=2
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pradyunsg/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-setuptools' 'python-dephell'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser')
checkdepends=('python-pytest' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/$pkgver.tar.gz")
sha512sums=('daa80c11e734ffa520779c7e08df4779f41dec429ebf642f024d575cfd952da0bbd0cc78190ca1b50bbcff3adf5cf5d97c4f1f605714d5f8fd40a21a64fbe623')

prepare() {
  cd $_pkgname-$pkgver

  dephell deps convert --from pyproject.toml --to setup.py
}

build() {
  cd $_pkgname-$pkgver

  python setup.py build

  PYTHONPATH=src sphinx-build -b dirhtml -v docs docs/build/html
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # remove windows entrypoint scripts executables
  rm "$pkgdir"/usr/lib/python*/site-packages/installer/_scripts/*.exe

  # install documentation
  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
