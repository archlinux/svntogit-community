# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.6.0
pkgrel=4
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/semantic-version"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest') # 'python-django') Test hangs
source=("$pkgbase-$pkgver.tar.gz::https://github.com/rbarrois/python-semanticversion/archive/v$pkgver.tar.gz")
sha512sums=('18db9279c2728565b13362c54bedbf569f0878cbe6bb58e631d87ffe7cff7d9131a30a2592cbf511091c03e854851159bbb298fe7469f53e8a2d92cf26ab4d0b')

build() {
  cd "$srcdir"/python-semanticversion-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/python-semanticversion-$pkgver
  rm tests/test_django.py
  py.test
}

package() {
  cd python-semanticversion-$pkgver
  python3 setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
