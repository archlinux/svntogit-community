# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.51.0
pkgrel=3
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('68b703bcb653ea09ca22ad5c94d662c729cee571839d38e98988e4d69e658d4aeb02198bd1a8f62c6041b662564fbe049c12b7b481cf874de4110af8c66b1c66')

build() {
  cd tqdm-$pkgver
  python setup.py build
}

check() {
  cd tqdm-$pkgver
  python setup.py egg_info
  python -m pytest
}

package() {
  cd tqdm-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENCE "$pkgdir"/usr/share/licenses/$pkgname/LICENCE
}

# vim:set ts=2 sw=2 et:
