# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=poetry-plugin-export
pkgname=python-poetry-plugin-export
pkgver=1.1.1
pkgrel=1
pkgdesc="Poetry plugin to export the dependencies to various formats "
url="https://github.com/python-poetry/poetry-plugin-export"
license=('MIT')
arch=('any')
depends=('python-poetry')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest-mock')
source=("https://github.com/python-poetry/poetry-plugin-export/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('61d31ddd0f5c84308a4e6d5691ea9ec52d3258244b99ce4200f706f5c20e24afc064812fcb3a7b0c4bbcb11bb9a6e1a20e616540493009f6ec101dab378b2318')

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
