# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-click-default-group
pkgver=1.2.2
pkgrel=7
pkgdesc="Extends click.Group to invoke a command without explicit subcommand name"
url="https://github.com/click-contrib/click-default-group"
license=('BSD')
arch=('any')
depends=('python-click')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("$pkgname-$pkgver.tar.gz::https://github.com/click-contrib/click-default-group/archive/v$pkgver.tar.gz"
        "$pkgname-click8.patch::https://github.com/click-contrib/click-default-group/pull/18.patch")
sha512sums=('6f296d154813e0c3dbf8e435c4c1b4394f51a000320c5585aeb78b81f30fe15bd27a8aad0fdbb71fccb88dc3083682519f1dd06572c8d5c35639fb9c3acf73fa'
            '515b12c0ebb09d097fbe16934d37dcd66b8f192f32dd32e92a642a093028c060b0d478632e65cb62c7bcd7cb784564d11f3ca3b151b15fa980ec76bfe730cabe')

prepare() {
  cd click-default-group-$pkgver
  patch -Np1 -i ../$pkgname-click8.patch
}

build() {
  cd click-default-group-$pkgver
  python setup.py build
}

check() {
  cd click-default-group-$pkgver
  python -m pytest
}

package() {
  cd click-default-group-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
