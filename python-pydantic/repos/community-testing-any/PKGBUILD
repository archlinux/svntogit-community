# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.9.1
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=(any)
url="https://github.com/samuelcolvin/pydantic"
license=(MIT)
depends=(python python-typing-extensions)
optdepends=(
  'python-dotenv: for .env file support'
  'python-email-validator: for email validation'
)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest python-pytest-mock)
source=($_name-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz)
sha512sums=('6343a4cbaf49c38bcf038da21ace9f37cbcd3f05364307c0b9b5006f3fe4c9db4513f557b5388783dbb08892dbdc2a54689988edf7d1bdc6e794b0e755213ecb')
b2sums=('94022c7ca8cfa29f51f814171d85d1b95f5a605fd685d47309f3f233bbb10d434a1f691f95c40dc99619284c81556d322cad7f63d486f7c3dcbe3d875827617c')

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
