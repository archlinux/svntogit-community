# Maintainer: David Runge <dvzrv@archlinux.org>

_name=crc32c
pkgname=python-crc32c
pkgver=2.3
pkgrel=2
pkgdesc="A python package implementing the crc32c algorithm in hardware and software"
arch=(x86_64)
url="https://github.com/ICRAR/crc32c"
license=(LGPL2.1 BSD)
depends=(python)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz)
sha512sums=('518148755fc4690d6b6d6146b9ac59a7e0ab96ff969e5e73b530f2738750586ae8311921baeb57bef6f75d4be23cddd4ef6ef69d2f6b65c9966a2b0a158dc2be')
b2sums=('1e023306e9448fc5fe951db6d21e6b8ada8b7a823c8080edb7f3d2f29e332913b0de5dfdc22d6c1cb89b5f23739b83d5deea8c582dcc012673bdc0e077aa0875')

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
  install -vDm 644 LICENSE.* -t "$pkgdir/usr/share/licenses/$pkgname/"
  install -vDm 644 README.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
