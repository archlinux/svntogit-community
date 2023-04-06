# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pyjwt
pkgver=2.6.0
pkgrel=2
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-cryptography')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('7b3d2aa5a12f51fb6b1137f939cfe6a08519b4d5b83f2c058dc31741e3ec6d7011844c7b426aa44aacf6570f3907a027ca1fe989a0c232e285e158a217f95557')

build() {
  cd pyjwt-$pkgver
  python setup.py build
}

check() {
  cd pyjwt-$pkgver
  pytest
}

package() {
  cd pyjwt-$pkgver
  python setup.py install --root="$pkgdir" -O1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
