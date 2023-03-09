# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.6
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=(x86_64)
url="https://github.com/pydantic/pydantic"
license=(MIT)
depends=(
  cython
  python
  python-typing-extensions
)
makedepends=(
  python-build
  python-installer
  python-importlib-metadata
  python-setuptools
  python-wheel
)
checkdepends=(
  python-hypothesis
  python-pytest
  python-pytest-mock
)
optdepends=(
  'python-dotenv: for .env file support'
  'python-email-validator: for email validation'
)
source=($url/archive/v$pkgver/$_name-v$pkgver.tar.gz)
sha512sums=('094fda0158faeb6021632f7ce3ea2570c19ddb288260d4e0f5a4361ab2684a68b0e6212264b37a4a75166746570098d1c4aa0311797d2cf1a22cef2c1e1f0137')
b2sums=('ba3a3896cdcd2eecc7bd4e6ad979846de377c94d939519889752b36827eba7b3d245943ba192dd80925c2aa09ef02243aaae5e990a6f7b1ab9a8d0b5ba9830c4')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  local deselected=(
    # we don't care about pytest warnings leading to errors
    --deselect tests/test_edge_cases.py::test_cython_function_untouched
  )
  cd $_name-$pkgver
  pytest -vv "${deselected[@]}"
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
