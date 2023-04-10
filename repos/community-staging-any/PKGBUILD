# Maintainer:
# Contributor: Mark Wagie <mark dot wagie at tutanota dot com>

pkgname=python-editables
_name=${pkgname#python-}
pkgver=0.3
pkgrel=4
pkgdesc='A Python library for creating editable wheels'
arch=(any)
url='https://github.com/pfmoore/editables'
license=(MIT)
depends=(python)
makedepends=(python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest)
source=(https://github.com/pfmoore/editables/archive/$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('42f7240164af1e028ccb7b60e72f54bbd8b639e9409595fbeffac5d3fb610643')

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_name-$pkgver 
  PYTHONPATH="$PWD"/src \
  pytest -v
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname
}
