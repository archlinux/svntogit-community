# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-pyjwt
pkgname=('python-pyjwt' 'python2-pyjwt')
pkgver=1.7.1
pkgrel=3
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-pytest-runner' 'python2-pytest-runner')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('0f61ad132309f896b6ea7f1a689854e643f4db6baf3a44d9f5b544b62e3fce384b95c3a04fe2a46aa3e1a5843c3550d57eaec5449c7faa56ca06562571940171')

prepare() {
  sed -i 's/pytest==2.7.3/pytest/;/pytest-cov/d' pyjwt-$pkgver/setup.py
  # do not use python-coverage
  sed -i 's/--cov-report term-missing --cov-config=.coveragerc --cov .//' pyjwt-$pkgver/setup.cfg
  cp -a pyjwt-$pkgver{,-py2}
}

build() {
  cd "$srcdir"/pyjwt-$pkgver
  python setup.py build

  cd "$srcdir"/pyjwt-$pkgver-py2
  python2 setup.py build
}

check() {
  cd "$srcdir"/pyjwt-$pkgver
  python setup.py pytest

  cd "$srcdir"/pyjwt-$pkgver-py2
  python2 setup.py pytest || warning "Tests failed"
}

package_python-pyjwt() {
  depends=('python-setuptools')

  cd pyjwt-$pkgver
  python3 setup.py install --root="$pkgdir" -O1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-pyjwt() {
  depends=('python2-setuptools')

  cd pyjwt-$pkgver-py2
  python2 setup.py install --root="$pkgdir" -O1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  mv "$pkgdir"/usr/bin/pyjwt{,2}
}
