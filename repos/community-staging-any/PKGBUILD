# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipreqs
pkgver=0.4.7
pkgrel=2
pkgdesc="Pip requirements.txt generator based on imports in project"
url="https://github.com/bndr/pipreqs"
license=('MIT')
arch=('any')
depends=('python-docopt' 'python-yarg')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bndr/pipreqs/archive/v$pkgver.tar.gz")
sha512sums=('c6f2c9fec0d00b2d853d46cf52c777f1e7a27e1ba63c0516ffee78c15f52387273ed5de6571ca7b837c7386f42ebaf57c08f26fead99f25de2249c484affa87c')

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
