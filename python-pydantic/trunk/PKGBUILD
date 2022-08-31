# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.0
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
checkdepends=(python-pytest python-pytest-mock)
source=($_name-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz)
sha512sums=('159b6d75ee3c633f3b6869aefe66bfb85bb4f21e1d93a00945263eb10fb63483fe70c70801588467e3569a0ded1649d66b7f433e8d0aabd4ad36540383aec353')
b2sums=('ce65b50840558ed7610045890dd852a998c8c1cef4694fc557068e70e7cbf93d5180c055b369a369c268f6b28ca1f4c208085df465ddfc1a3122747f2161a702')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_name-$pkgver
  pytest -vv
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname/"
}
