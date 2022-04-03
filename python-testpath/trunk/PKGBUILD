# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Philipp A. <flying-sheep@web.de>
_name=testpath
pkgname=python-testpath
pkgver=0.6.0
pkgrel=1
pkgdesc='Test utilities for code working with files and commands'
arch=('any')
url="https://pypi.python.org/pypi/testpath"
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-flit-core')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/t/$_name/$_name-$pkgver.tar.gz")
md5sums=('9fd4339f76da12d15bc718e4aa2566e9')

prepare() {
  cd $_name-$pkgver
  rm testpath/cli*.exe
}

build() {
  cd $_name-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd $_name-$pkgver
  pytest -v
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}
