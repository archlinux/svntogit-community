# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgname=python-latexcodec
pkgver=1.0.7
pkgrel=2
pkgdesc="A lexer and codec to work with LaTeX code in Python"
arch=('any')
url="https://github.com/mcmtroffaes/latexcodec"
license=('MIT')
depends=('python-six')
makedepends=('python-setuptools')
checkdepends=('python-nose')
source=("https://pypi.io/packages/source/l/latexcodec/latexcodec-$pkgver.tar.gz")
sha256sums=('ebc183904549b1514ffc29a8768c8b58dc45cb813b94df90bf19f4c7b01fd772')

build() {
  cd "$srcdir/latexcodec-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/latexcodec-$pkgver"
  nosetests
}

package() {
  cd "$srcdir/latexcodec-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
