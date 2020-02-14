# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.8.3
pkgrel=1
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("$pkgname-$pkgver.tar.gz::https://github.com/rbarrois/python-semanticversion/archive/$pkgver.tar.gz")
sha512sums=('707b30aabffbbe2117f5039d8ec03eb129e395b4293299650d2a20f55cc63cedf199df7fc0cb90badc0c1cea0741e679a0a146f4f373332ffeeadfeb391e2ae5')

build() {
  cd python-semanticversion-$pkgver
  python setup.py build
}

check() {
  cd python-semanticversion-$pkgver
  py.test
}

package() {
  cd python-semanticversion-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
