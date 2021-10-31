# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pipreqs
pkgver=0.4.11
pkgrel=1
pkgdesc="Pip requirements.txt generator based on imports in project"
url="https://github.com/bndr/pipreqs"
license=('MIT')
arch=('any')
depends=('python-docopt' 'python-yarg')
makedepends=('python-setuptools')
source=("$pkgname-$pkgver.tar.gz::https://github.com/bndr/pipreqs/archive/v$pkgver.tar.gz")
sha512sums=('7ce21dad28d5fb672026fde1f1f324d858666d6f803c241a569f59aa20b6513f74796b25066c53d83b036321f5c743e7e362718cec524e529578817ba832839d')

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
