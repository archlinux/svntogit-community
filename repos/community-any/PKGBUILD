# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=poetry-plugin-export
pkgname=python-poetry-plugin-export
pkgver=1.1.0
pkgrel=1
pkgdesc="Poetry plugin to export the dependencies to various formats "
url="https://github.com/python-poetry/poetry-plugin-export"
license=('MIT')
arch=('any')
depends=('python-poetry')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest-mock')
source=("https://github.com/python-poetry/poetry-plugin-export/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('a967d5267f6e8c69dd6e63b2b94e9351ad8a9ff91a6c36ff9db18a7c6f33e6f18e4d1aa0c19e8553f22aa45b357b756e663d5d1aa33f9b7b0ddf3a1dd050ed40')

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
