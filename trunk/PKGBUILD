# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pyjwt
pkgver=1.7.1
pkgrel=5
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
depends=('python-setuptools')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('0f61ad132309f896b6ea7f1a689854e643f4db6baf3a44d9f5b544b62e3fce384b95c3a04fe2a46aa3e1a5843c3550d57eaec5449c7faa56ca06562571940171')

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
