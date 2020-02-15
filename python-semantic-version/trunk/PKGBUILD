# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.8.4
pkgrel=1
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("$pkgname-$pkgver.tar.gz::https://github.com/rbarrois/python-semanticversion/archive/$pkgver.tar.gz")
sha512sums=('4c847d7adb478349b4d8444adddde12802c2ca56355dd2b6cd943d7869d221ddf0242ecbef7dc34e591b9b13f2e7dfd0e84310d31c0f7074de599f8950668de7')

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
