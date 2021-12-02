# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-dict2xml
pkgver=1.7.0
_commit=ea9282f263b6588d59ac6998bf2319002527bd13
pkgrel=2
pkgdesc="Small utility to convert a python dictionary into an XML string"
arch=('any')
url="https://github.com/delfick/python-dict2xml"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-noseofyeti')
source=("https://github.com/delfick/python-dict2xml/archive/$_commit/$pkgname-$_commit.tar.gz")
sha512sums=('1fc2a25c903adca106374ea9181b57da25f2166eed9cc45a3ebcc4e7d90a6f20f4fa9f541048f35ab93af36e6ba55786b989e058443f7a6cbaf9a3838a1f4d0a')

build() {
  cd python-dict2xml-$_commit
  python setup.py build
}

check() {
  cd python-dict2xml-$_commit
  pytest
}

package() {
  cd python-dict2xml-$_commit
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
