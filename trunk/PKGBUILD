# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-tqdm
pkgver=4.52.0
pkgrel=1
pkgdesc='Fast, Extensible Progress Meter'
arch=('any')
license=('MIT' 'MPL')
url='https://github.com/tqdm/tqdm'
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-coverage' 'flake8')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tqdm/tqdm/archive/v$pkgver.tar.gz")
sha512sums=('0026f95f6deafebe444443222672c2adb2cd4b7d0b5fccdf51162ac020dbb8a30341e87aa552612091992d3550e8d89784bee626c5853d902c45030b044579b9')

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
