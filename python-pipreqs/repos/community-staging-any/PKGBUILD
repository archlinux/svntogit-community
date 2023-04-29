# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipreqs
pkgver=0.4.12
pkgrel=1
pkgdesc="Pip requirements.txt generator based on imports in project"
url="https://github.com/bndr/pipreqs"
license=('MIT')
arch=('any')
depends=('python-docopt' 'python-yarg')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bndr/pipreqs/archive/v$pkgver.tar.gz")
sha512sums=('af759fd530b5eca0b596dc1d2ccb92900c69bc9499575d2977d0549d7de0dd97f6e8cf28b6060309832c64cd6b779f006edcb97234eeae734e64eb19188d201b')

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
