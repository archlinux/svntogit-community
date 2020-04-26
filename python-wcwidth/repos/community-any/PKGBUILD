# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: wenLiangcan <boxeed at gmail dot com>

pkgbase=python-wcwidth
pkgname=(python-wcwidth python2-wcwidth)
_name=wcwidth
pkgver=0.1.9
pkgrel=1
pkgdesc="Measures number of Terminal column cells of wide-character codes"
url="https://github.com/jquast/wcwidth"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python2-setuptools')
source=("https://files.pythonhosted.org/packages/source/w/$_name/$_name-$pkgver.tar.gz")
md5sums=('b32584cd6084b4a8c81df13a2a6b4351')

prepare() {
  cd "$srcdir"
  cp -r $_name-$pkgver python2-$_name-$pkgver
}

package_python-wcwidth() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-wcwidth() {
  depends=('python2')
  cd "$srcdir/python2-$_name-$pkgver"
  python2 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm644 LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
