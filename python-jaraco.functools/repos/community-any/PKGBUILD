# Maintainer: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.functools
# https://github.com/jaraco/jaraco.functools/blob/main/CHANGES.rst
pkgver=3.6.0
pkgrel=1
pkgdesc='Functools like those found in stdlib'
arch=('any')
url='https://github.com/jaraco/jaraco.functools'
license=('MIT')
depends=('python-more-itertools')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest' 'python-jaraco.classes')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.functools/jaraco.functools-$pkgver.tar.gz")
sha512sums=('f249e6cdcbd88e5c89663bcc0467687ea533dc70b7c9260880da8099380b5c925f05933527de6043aa0786709a0ca4d4b183cc18acab69d8e88f63a3360e9efb')

build() {
  cd jaraco.functools-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd jaraco.functools-$pkgver
  pytest
}

package() {
  cd jaraco.functools-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
