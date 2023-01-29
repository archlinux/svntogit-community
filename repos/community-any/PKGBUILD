# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.12.0
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-jaraco.itertools' 'python-func-timeout' 'python-more-itertools')
source=("https://github.com/jaraco/zipp/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('6fbd9c1a56147e88ae80e6a603d49c472241b59285e5e8bcf62ea677db72daaa78b1be585666c73e910b53520f74fdd9add9e7ee50c463b75e745f5a24880151')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd zipp-$pkgver
  python -m build -nw
}

check() {
  cd zipp-$pkgver
  python -m unittest discover
}

package() {
  cd zipp-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
