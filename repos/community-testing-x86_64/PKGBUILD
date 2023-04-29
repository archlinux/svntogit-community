# Maintainer: Kyle Keen <keenerd@gmail.com>

pkgname=python-cwcwidth
_pkgname=cwcwidth
pkgver=0.1.8
pkgrel=2
pkgdesc="Bindings for wcwidth and wcswidth functions defined in POSIX.1-2001 and POSIX.1-2008"
arch=('x86_64')
url="https://pypi.org/project/cwcwidth/"
license=('MIT')
depends=('glibc')
makedepends=('python-build' 'python-installer' 'cython' 'python-setuptools' 'python-wheel')
source=("$_pkgname-$pkgver.tgz::https://github.com/sebastinas/cwcwidth/archive/refs/tags/v$pkgver.tar.gz")
sha256sums=('fb75854b7cb6b2447f464555a795ae7c4a9a43f51c921ebb14d340ac2b9b97fb')

build() {
  cd $_pkgname-$pkgver
  python3 -m build --wheel --no-isolation
}

package() {
  cd $_pkgname-$pkgver
  python3 -m installer --destdir="$pkgdir/" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
