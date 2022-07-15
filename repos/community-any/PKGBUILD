# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-zipp
pkgver=3.8.1
pkgrel=1
pkgdesc="Pathlib-compatible object wrapper for zip files"
url="https://github.com/jaraco/zipp"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-toml' 'python-wheel')
checkdepends=('python-jaraco.itertools' 'python-func-timeout')
source=("https://github.com/jaraco/zipp/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('e720ea96f137d59d09c43024a410c0089e2986ef6c091df1779e1bd46573220c84c56c9454f3ace03b728bc8941b8993d003e728afe8def6b43345f9c99bf2aa')

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
