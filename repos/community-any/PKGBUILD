# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.16
pkgrel=2
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-whatever')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/funcy/archive/$pkgver.tar.gz")
sha512sums=('b70e3781463a4b9df6ee892150889eacbfff707a90e1985f906173f0bb2fa512cb4bf4e2227c785f1066206b5c5be0e9eab5cf6be3a726f84eb4dbd06d88c575')

build() {
  cd funcy-$pkgver
  python setup.py build
}

check() {
  cd funcy-$pkgver
  python setup.py pytest
}

package() {
  cd funcy-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
