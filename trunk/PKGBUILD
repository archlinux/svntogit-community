# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.3
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=(x86_64)
url="https://github.com/pydantic/pydantic"
license=(MIT)
depends=(cython python python-typing-extensions)
optdepends=(
  'python-dotenv: for .env file support'
  'python-email-validator: for email validation'
)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-hypothesis python-pytest python-pytest-mock)
source=($_name-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz)
sha512sums=('7c9db4a010f14ab41b0e7782e59e51caded5de31798e4dd83e01037e3365e34537b30c79c12a6451fdee875e1bfe1a3d981cae58aa373917f71489231df2e6a6')
b2sums=('e8cec71f0d3f66e2c71e421505f624f7e92827f8fe4ef3a7c637b4f2cbc543d43e63739f8fed1a84246458d6675f19de9f83c7fc2a1d8f6e9fb18807ad5ace6f')

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
