# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.13
pkgrel=2
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-whatever')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/funcy/archive/$pkgver.tar.gz")
sha512sums=('766a46e644d69e1a655d7218439b3bbf3ad8569070fcdb35faa22253fc820adda3c1e570939883a1481dcc686e13e2bc53bf2e95fe4b047a85bef69385d3bf84')

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
