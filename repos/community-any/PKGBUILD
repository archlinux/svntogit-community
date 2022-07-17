# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pyjwt
pkgver=2.4.0
pkgrel=1
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
depends=('python-setuptools')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('c1044de436394d7758bdfcc9256a1ff4534881b9e5cd29b6055bcfed349b4d0d3e0b802a8163740adf63f624394e7ef7f61a91e3b49f7bae914165a2549ce771')

prepare() {
  sed -i 's/pytest==2.7.3/pytest/;/pytest-cov/d' pyjwt-$pkgver/setup.py
  # do not use python-coverage
  sed -i 's/--cov-report term-missing --cov-config=.coveragerc --cov .//' pyjwt-$pkgver/setup.cfg
}

build() {
  cd "$srcdir"/pyjwt-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/pyjwt-$pkgver
  python setup.py pytest
}

package() {
  cd pyjwt-$pkgver
  python3 setup.py install --root="$pkgdir" -O1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
