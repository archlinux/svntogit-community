# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-dict2xml
pkgver=1.7.3
pkgrel=2
pkgdesc="Small utility to convert a python dictionary into an XML string"
arch=('any')
url="https://github.com/delfick/python-dict2xml"
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-installer' 'python-hatchling')
checkdepends=('python-pytest' 'python-noseofyeti')
source=("https://github.com/delfick/python-dict2xml/archive/release-$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('5520c10fe9965c507684d282adbf31a80604c0f043d9cfe912a235779536af2a671d34570a0fea31d16b686c679ceca54a3641f727a4ba4f2036d6c5784df433')

build() {
  cd python-dict2xml-release-$pkgver
  python -m build -nw
}

check() {
  cd python-dict2xml-release-$pkgver
  pytest
}

package() {
  cd python-dict2xml-release-$pkgver
  python -m installer -d "$pkgdir" dist/*.whl

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
