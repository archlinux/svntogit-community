# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.15
pkgrel=2
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-whatever')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/funcy/archive/$pkgver.tar.gz")
sha512sums=('876a26905fb9f1a88c3d1e82984ee29772dbe22ed12ca7e6ff49ccae4dd8c06280802aa8d65e926e0d4bfe28a65770d4b5d4832318761ad6e1e0fec6d1ab1666')

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
