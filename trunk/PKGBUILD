# Maintainer:

pkgname=python-hatch-fancy-pypi-readme
pkgver=22.3.0
pkgrel=1
pkgdesc='Fancy PyPI READMEs with Hatch'
arch=(any)
url='https://github.com/hynek/hatch-fancy-pypi-readme'
license=(MIT)
depends=(python-hatchling)
makedepends=(python-build python-installer)
checkdepends=(python-pytest python-wheel)
source=(https://github.com/hynek/hatch-fancy-pypi-readme/archive/$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('3a51bbe0eb5044f012083ce2954e0875116553429289d29712b824defe90fab0')

build() {
  cd hatch-fancy-pypi-readme-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd hatch-fancy-pypi-readme-$pkgver
  PYTHONPATH="$PWD"/src \
  pytest -v
}

package() {
  cd hatch-fancy-pypi-readme-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
