# Maintainer: David Runge <dvzrv@archlinux.org>
# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_name=pydantic
pkgname=python-$_name
pkgver=1.9.2
pkgrel=1
pkgdesc='Data parsing and validation using Python type hints'
arch=(x86_64)
url="https://github.com/samuelcolvin/pydantic"
license=(MIT)
depends=(cython python python-typing-extensions)
optdepends=(
  'python-dotenv: for .env file support'
  'python-email-validator: for email validation'
)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest python-pytest-mock)
source=($_name-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz)
sha512sums=('06c2c45d553e622f1c71283468016ea507982dd8c74af673c18818d61a5712c8ec6820f2caaa392c5582802c413a4cf14e5ff67586da7c6ddf5b4e85a936d335')
b2sums=('a271032d0e128a91897b5b10f0dae797f41d0d969fef65792cbf3d790b72ae0523a78c2f0d88599b2c3c7e2c9a917883809a88a7aa66e915d0749fabfed0c61f')

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
