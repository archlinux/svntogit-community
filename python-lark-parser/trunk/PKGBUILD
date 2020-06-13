# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-lark-parser
pkgver=0.8.7
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
sha512sums=('a694ccade00ab97ce655a80238d37f1288c33a82293a0aac9b60c99cf89ed1bd4ce745fb9015d92829998c4dd956cbce6744cb93f3ffa704061d7a36544c0078'
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
