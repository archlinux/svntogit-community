# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-dict2xml
pkgver=1.7.2
pkgrel=1
pkgdesc="Small utility to convert a python dictionary into an XML string"
arch=('any')
url="https://github.com/delfick/python-dict2xml"
license=('MIT')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-noseofyeti')
source=("https://github.com/delfick/python-dict2xml/archive/release-$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('5da174aaa005a51177335d956977e9b82be55f343f1209515346bdf6ec27fe2909796928995f261aa88f1bb4ff0ec62facedf22febab4562ab868e0dd71ad7ab')

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
