# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: wenLiangcan <boxeed at gmail dot com>

pkgbase=python-wcwidth
pkgname=(python-wcwidth python2-wcwidth)
_name=wcwidth
pkgver=0.2.5
pkgrel=1
pkgdesc="Measures number of Terminal column cells of wide-character codes"
url="https://github.com/jquast/wcwidth"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools' 'python2-setuptools' 'python2-backports.functools_lru_cache')
source=("https://files.pythonhosted.org/packages/source/w/$_name/$_name-$pkgver.tar.gz")
md5sums=('a07a75f99d316e14838ac760c831ea37')

prepare() {
  cd "$srcdir"
  cp -r $_name-$pkgver python2-$_name-$pkgver
}

package_python-wcwidth() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-wcwidth() {
  depends=('python2' 'python2-backports.functools_lru_cache')
  cd "$srcdir/python2-$_name-$pkgver"
  python2 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
