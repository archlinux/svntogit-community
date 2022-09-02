# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=poetry-plugin-export
pkgname=python-poetry-plugin-export
pkgver=1.0.6
pkgrel=2
pkgdesc="Poetry plugin to export the dependencies to various formats "
url="https://github.com/sdispater/poetry-plugin-export"
license=('MIT')
arch=('any')
depends=('python-poetry')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest-mock')
source=("https://github.com/python-poetry/poetry-plugin-export/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('61afdbff0dd0e7ded56b1b4c428cd0b4dd07c66e8bfa236a4ab178f08a12e6e13600a7274b7802f6cd339ccad1c40846a700dc42349cfadf180123734f333a03')

prepare() {
  cd poetry-plugin-export-$pkgver
  # Patch out the dependency on poetry because `build` couldn't handle circular dependency:
  # https://github.com/pypa/build/issues/511
  sed -i '/^poetry =/d' pyproject.toml
}

build() {
  cd poetry-plugin-export-$pkgver
  python -m build -wn
}

check() {
  cd poetry-plugin-export-$pkgver
  python -m installer -d tmp_install dist/*.whl
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" pytest
}

package() {
  cd poetry-plugin-export-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
