# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-lark-parser
pkgver=0.8.1
_nearley_commit=a46b37471db486db0f6e1ce6a2934fb238346b44
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
sha512sums=('3307593b21de3e70709f3d1f2e2bc2c19fc39d686fe1819a432510fc9f3e4cc4aca6737410b75f1a3829736cb7a97476b5a9202b5d5aa85c7ef01d8100a33cef'
            'fe14909f8a1d1626f8a632e8d48bf83602923f468b7bbb819557b85ab5e384cb042241ba15525e9850f2bbd65cad12497ed0b7ff6bc86c04d78b63d0c1bb66b4')

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
