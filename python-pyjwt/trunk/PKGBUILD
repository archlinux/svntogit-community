# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pyjwt
pkgver=2.2.0
pkgrel=1
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
depends=('python-setuptools')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('b7f30089f0c0152636469be3555c4e865bb47bd9d30947c7d6ec4011d4b2a02a0ea9e78c8e93eb803cc90010cf3eeacc51854e517dc1873e8bca59f27227ea1b')

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
