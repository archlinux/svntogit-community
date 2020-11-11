# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.8.5
pkgrel=3
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("$pkgname-$pkgver.tar.gz::https://github.com/rbarrois/python-semanticversion/archive/$pkgver.tar.gz")
sha512sums=('e59508b12ac0f1b46f1d97f633f5bead99c41542c51c2714a4074eda9da6a04cd103be20eafd031b541834b6ee99b4f9f9ee9baec58b9f8a313d0c727aeab68d')

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
