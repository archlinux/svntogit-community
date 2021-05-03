# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.2.0
pkgrel=1
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pradyunsg/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-setuptools' 'python-dephell'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser')
checkdepends=('python-pytest' 'python-mock')
source=("$pkgname-$pkgver.tar.gz::$url/archive/refs/tags/$pkgver.tar.gz")
sha512sums=('f3acce41d5547e3a9dfcab79b52f81f479ac195b5f52884262a87b9b342658f23d235eb1e840bf8b18fb757bd3f25c63fc0120703bf33b8a177ff5078f8f983a')

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
