# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.4
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
sha512sums=('0566f89518c6f0171c9b49b5fb57e568286ed421d64655dde90a1565d0672bfef6237ed99e4120564ca2562c7e29e08d86db4fcec47e605aaa98d60845688e72')
b2sums=('506a53de6a59f858a7c8fd56cf18f8079d48eb4f6d3ba36d149141a7e2d471819a466bfc1c34c879f5ec90c0de385b2b89d58beb75660da7de282278092e901f')

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
