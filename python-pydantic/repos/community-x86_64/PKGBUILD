# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.5
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=(x86_64)
url="https://github.com/pydantic/pydantic"
license=(MIT)
depends=(cython python python-typing-extensions)
makedepends=(
  python-build
  python-installer
  python-importlib-metadata
  python-setuptools
  python-wheel
)
checkdepends=(python-hypothesis python-pytest python-pytest-mock)
optdepends=(
  'python-dotenv: for .env file support'
  'python-email-validator: for email validation'
)
source=($url/archive/v$pkgver/$_name-v$pkgver.tar.gz)
sha512sums=('2f25e5ed3016a64af05674a21dd8dccf3af7e075237b0d078433fa347e58482113e243f9c21ddd55677432d22da692cbb24a682c5af2f09bfdb6fb5cbd53d408')
b2sums=('6ad75bc0e58b2fea8e0e4c2e23e7b8de39779ec6f1acf05b693201f6ef63e2e6765cac2320ecf694086facdc5d38d9213cead7dc267b53bbec97f11e0f6ff67e')

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
