# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.7
pkgrel=4
pkgdesc='Data parsing and validation using Python type hints'
arch=(x86_64)
url="https://github.com/pydantic/pydantic"
license=(MIT)
depends=(
  glibc
  python
  python-typing-extensions
)
makedepends=(
  cython
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
sha512sums=('948a7935b374719773df50243aed708b3c6789243b9aa0ba239cf1502ddd0e0cec4d701e108f1cc78090c088f3cb1c78b840c39f5e7ad0e61739776f552f284d')
b2sums=('b2dd75a640ca54024a2bf141117a1d738a30a4630bed8f4d0169fc5a6a55ded719727d88c7e78b9a2acc3aec68482e9be8c8bf4776fef668fe4acc3e1fd775df')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  local pytest_options=(
    # we don't care about pytest warnings leading to errors
    --pythonwarnings ignore::DeprecationWarning:pkg_resources
  )

  cd $_name-$pkgver
  pytest -vv "${pytest_options[@]}"
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
