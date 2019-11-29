# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-funcy
pkgver=1.14
pkgrel=1
pkgdesc='A fancy and practical functional tools'
arch=('any')
license=('BSD')
url='https://github.com/Suor/funcy'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner' 'python-whatever')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Suor/funcy/archive/$pkgver.tar.gz")
sha512sums=('1844bf34f8cda440fc72e3b9ec455c10ab4410f63992d8d29dca91e96d78e034f4f1a5845a89cc3fe9659675b4eb3574b90fe3265aebb541bd4444bf6f6b2332')

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
