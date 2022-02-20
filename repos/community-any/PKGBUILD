# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-dict2xml
pkgver=1.7.1
pkgrel=1
pkgdesc="Small utility to convert a python dictionary into an XML string"
arch=('any')
url="https://github.com/delfick/python-dict2xml"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-noseofyeti')
source=("https://github.com/delfick/python-dict2xml/archive/release-$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('ed8f80df44fae7dd0d82b504d9982809ee3aefda9bcb3b5ba88d9cc1222ad5548a0a2f9b35ad1e8e032e69d957141e21a4bc8e169640d4b98423fbd10b5c7ed7')

build() {
  cd python-dict2xml-release-$pkgver
  python setup.py build
}

check() {
  cd python-dict2xml-release-$pkgver
  pytest
}

package() {
  cd python-dict2xml-release-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
