# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-lark-parser
pkgname=(python-lark-parser python2-lark-parser)
pkgver=0.7.8
_nearley_commit=a46b37471db486db0f6e1ce6a2934fb238346b44
pkgrel=3
pkgdesc="A modern parsing library"
url="https://github.com/lark-parser/lark"
license=('MIT')
arch=('any')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-js2py' 'python2-js2py')
source=("$pkgbase-$pkgver.tar.gz::https://github.com/lark-parser/lark/archive/$pkgver.tar.gz"
        "nearley-$_nearley_commit.tar.gz::https://github.com/kach/nearley/archive/$_nearley_commit.tar.gz")
sha512sums=('3f6093d600744e23f32622bc40017873ecd54b44757b761f007606827411964bb38e3b5c0c23373ff0caea2ab73d6ed1c834d5444cedce0cef762c512a1aa669'
            'fe14909f8a1d1626f8a632e8d48bf83602923f468b7bbb819557b85ab5e384cb042241ba15525e9850f2bbd65cad12497ed0b7ff6bc86c04d78b63d0c1bb66b4')

prepare() { 
  rmdir lark-$pkgver/tests/test_nearley/nearley
  ln -s "$srcdir"/nearley-$_nearley_commit lark-$pkgver/tests/test_nearley/nearley
}

build() {
  cd lark-$pkgver
  python setup.py build
  python2 setup.py build
}

check() {
  cd lark-$pkgver
  python -m tests
  python2 -m tests
}

package_python-lark-parser() {
  depends=('python')

  cd lark-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-lark-parser() {
  depends=('python2')

  cd lark-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
