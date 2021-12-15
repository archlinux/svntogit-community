# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: wenLiangcan <boxeed at gmail dot com>

pkgname=python-wcwidth
_name=wcwidth
pkgver=0.2.5
pkgrel=6
pkgdesc="Measures number of Terminal column cells of wide-character codes"
url="https://github.com/jquast/wcwidth"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/w/$_name/$_name-$pkgver.tar.gz")
md5sums=('a07a75f99d316e14838ac760c831ea37')

package() {
  cd "$srcdir/$_name-$pkgver"
  python3 setup.py install --root="${pkgdir}" --optimize=1
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
