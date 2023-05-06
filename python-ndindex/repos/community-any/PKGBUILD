# Maintainer:

_pyname=ndindex
pkgname=python-$_pyname
pkgver=1.7
pkgrel=1
pkgdesc='Library for manipulating indices of ndarrays'
arch=(any)
url='https://quansight-labs.github.io/ndindex/'
license=(MIT)
depends=(python-numpy)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest-cov python-hypothesis python-pyflakes)
source=(https://github.com/Quansight-Labs/ndindex/archive/$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('388f45290393262b69ee440053bfe1664cdac6a125b29c2ea2569cdc3943dbbe')

prepare() {
  cd $_pyname-$pkgver
  sed -e 's|--flakes||' -i pytest.ini
}

build() {
  cd $_pyname-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_pyname-$pkgver
  pytest -v
}

package() {
  cd $_pyname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
}
