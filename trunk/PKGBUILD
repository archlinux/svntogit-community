# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.12
pkgrel=1
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-whatever')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/funcy/archive/$pkgver.tar.gz")
sha512sums=('719ba558fea175a97ebe24ed7a8e9026638211ccb76678538f6fb9d879b443e9bf8eea1603105ab5d42ba9480c78a6792cde6b69d491d0d2fcda4edbe6687f5c')

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
