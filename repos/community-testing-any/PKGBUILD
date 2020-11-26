# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipreqs
pkgver=0.4.10
pkgrel=3
pkgdesc="Pip requirements.txt generator based on imports in project"
url="https://github.com/bndr/pipreqs"
license=('MIT')
arch=('any')
depends=('python-docopt' 'python-yarg')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bndr/pipreqs/archive/v$pkgver.tar.gz")
sha512sums=('031fb48122f4e63d4df6a773567e69d8cf0746cdc846b9166d5b5c52bfa18ee309666926a75d43eecbf89f11e6cdc97789c4fd7cd9e42e2c497e992b767e8f3b')

build() {
  cd pipreqs-$pkgver
  python setup.py build
}

check() {
  cd pipreqs-$pkgver
  python setup.py test
}

package() {
  cd pipreqs-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
