# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Philipp A. <flying-sheep@web.de>
_name=testpath
pkgname=python-testpath
pkgver=0.5.0
pkgrel=2
pkgdesc='Test utilities for code working with files and commands'
arch=('any')
url="https://pypi.python.org/pypi/testpath"
license=('MIT')
depends=('python')
#makedepends=('python-pip')
_wheel="$_name-$pkgver-py2.py3-none-any.whl"
source=("https://pypi.io/packages/source/t/$_name/$_name-$pkgver.tar.gz")
md5sums=('b3a41d75aadeab905f7014a3189e852b')

prepare() {
  cd "$_name-$pkgver"
  rm testpath/cli*.exe
}

package() {
  cd "$_name-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
