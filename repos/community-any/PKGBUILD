# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-lark-parser
pkgver=1.1.3
_nearley_commit=326831689826cb1b9a4d21d1ce0d5db9278e9636 
pkgrel=1
pkgdesc="A modern parsing library"
url="https://github.com/lark-parser/lark"
license=('MIT')
arch=('any')
depends=('python')
makedepends=('python-setuptools')
checkdepends=('python-js2py')
source=("$pkgname-$pkgver.tar.gz::https://github.com/lark-parser/lark/archive/$pkgver.tar.gz"
        "nearley-$_nearley_commit.tar.gz::https://github.com/kach/nearley/archive/$_nearley_commit.tar.gz")
sha512sums=('785927920a8175752dd72c32dad251389280f0b2e1d5f751f127912c54673a8f874c4af3a01639245e9ff9d63c8a5d92ac9be1dd6bec64cee62c553cecee43c8'
            '88849bfa609c112a7687d8aba1fc140b1b6be119f7001869e7c05019e87c31874a6d0c9fb2c68b5729c4b4427ff05e36057857cea11bd51d2b5d89e7710196b7')

prepare() {
  rmdir lark-$pkgver/tests/test_nearley/nearley
  ln -s "$srcdir"/nearley-$_nearley_commit lark-$pkgver/tests/test_nearley/nearley
}

build() {
  cd lark-$pkgver
  python setup.py build
}

check() {
  cd lark-$pkgver
  python -m tests
}

package() {
  cd lark-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
