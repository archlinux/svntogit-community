# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Simon Sapin <simon dot sapin at exyr dot org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-semantic-version
pkgver=2.10.0
pkgrel=3
pkgdesc="A library implementing the 'SemVer' scheme."
url="https://github.com/rbarrois/python-semanticversion"
license=('BSD')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-django')
source=("https://github.com/rbarrois/python-semanticversion/archive/$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('e060dd60db62663c6ebf21fdca33b2390d9bbad15fbdfa504221ab646426f09168caf00e79cee7ed4ef442c23fd587c9e421aa744990101ea626b58f4e320242')

build() {
  cd python-semanticversion-$pkgver
  python setup.py build
}

check() {
  cd python-semanticversion-$pkgver
  python setup.py egg_info
  pytest
}

package() {
  cd python-semanticversion-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
