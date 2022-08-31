# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.10.1
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
sha512sums=('2be3f10a82d655a94b3f250ed4c78439b4195dde3f7f6aa66028105b5c9b0e56aa8176701d563e5372533ae34e0b6d0fe2254df9429b04815607bcfc94e40370')
b2sums=('5ca8d11528c7a7666136224c97dd0b078cf6f936a23227aa9dcd62af3c6a0af8f07c4c92751bd2c203497a626d4f93a78fd594bfc71dd0c43886c2dacc257af4')

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
