# Maintainer: Felix Yan <felixonmars@archlinux.org>

_pkgname=poetry-plugin-export
pkgname=python-poetry-plugin-export
pkgver=1.3.0
pkgrel=3
pkgdesc="Poetry plugin to export the dependencies to various formats "
url="https://github.com/python-poetry/poetry-plugin-export"
license=('MIT')
arch=('any')
depends=('python-poetry')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest-mock' 'python-pytest-xdist')
source=("https://github.com/python-poetry/poetry-plugin-export/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('cdb0cece91470141956833780dfcad676e99b51fa6158521401499b8f67c3e6f954ce16e227b7916336cef011f4a7b651948a8440852253fe57753eb40bbf8e5')

build() {
  cd poetry-plugin-export-$pkgver
  python -m build -wn
}

check() {
  cd poetry-plugin-export-$pkgver
  python -m installer -d tmp_install dist/*.whl
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  PYTHONPATH="$PWD/tmp_install/$site_packages" pytest
}

package() {
  cd poetry-plugin-export-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE
}
