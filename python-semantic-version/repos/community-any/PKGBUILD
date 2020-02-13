# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.8.2
pkgrel=1
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("$pkgname-$pkgver.tar.gz::https://github.com/rbarrois/python-semanticversion/archive/$pkgver.tar.gz")
sha512sums=('d6d7b3eac904c5bb0f73e2c13addcc4c4176c442f8a2139c4b920ceaf4240dfb75a28be074ad36fda175650103412fff97c82a91ece37e864e3e0a1aa411acfb')

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
