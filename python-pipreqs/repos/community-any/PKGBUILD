# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipreqs
pkgver=0.4.8
pkgrel=1
pkgdesc="Pip requirements.txt generator based on imports in project"
url="https://github.com/bndr/pipreqs"
license=('MIT')
arch=('any')
depends=('python-docopt' 'python-yarg')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bndr/pipreqs/archive/v$pkgver.tar.gz")
sha512sums=('6e89ec5a20e078c3b3be28c6157d1f795c73ce545e1436b64211e799177d56ab2d9382df44936210ffd1f626e5a5cbf6f7a0a3901bffc677f4c6b2b47b2ecd85')

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
