# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pyjwt
pkgver=2.5.0
pkgrel=1
pkgdesc='JSON Web Token implementation in Python'
arch=('any')
url='https://github.com/jpadilla/pyjwt'
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-cryptography')
source=("$pkgname-$pkgver.tar.gz::https://github.com/jpadilla/pyjwt/archive/$pkgver.tar.gz")
sha512sums=('7db32dd621a9744d561ec1dc1fe923326fd2425c56ae76df78e024146cf1520ac703a78d250b37090393747ea1d01872903cc86eba803b733beac11b4f803422')

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
