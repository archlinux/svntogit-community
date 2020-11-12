# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-deprecated
pkgver=1.2.10
pkgrel=3
pkgdesc="Python @deprecated decorator to deprecate old python classes, functions or methods"
url="https://github.com/tantale/deprecated"
license=('MIT')
arch=('any')
depends=('python-wrapt')
makedepends=('python-setuptools')
checkdepends=('python-pytest-runner')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tantale/deprecated/archive/v$pkgver.tar.gz"
        $pkgname-py39.patch::https://github.com/tantale/deprecated/commit/efb3e60623e1.patch)
sha512sums=('4bd53b759d04ab15c74a4c147b2c69c73aed6e40555acf0e84cf0c5b7ffe248da234bd1311c5629f9357d50bc08e55e81363340dcfdabe88933525bcc7859a70'
            'a7b000ab15dbdf9f3041da4475d97abab2e8649bd6809f97ee032ff656588cbcac915a417e1dbc4dfc310af5809c2bba343bd156412a742117284eab5aef083c')

prepare() {
  cd "$srcdir"/deprecated-$pkgver
  patch -Np1 -i ../$pkgname-py39.patch
}

build() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py build
}

check() {
  cd "$srcdir"/deprecated-$pkgver
  python setup.py pytest
}

package() {
  cd deprecated-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE.rst "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.rst
}
