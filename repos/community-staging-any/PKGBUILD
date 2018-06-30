# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgbase=python-latexcodec
pkgname=(python-latexcodec python2-latexcodec)
pkgver=1.0.5
pkgrel=2
pkgdesc="A lexer and codec to work with LaTeX code in Python"
arch=('any')
url="https://github.com/mcmtroffaes/latexcodec"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-nose' 'python2-nose')
source=("https://pypi.io/packages/source/l/latexcodec/latexcodec-$pkgver.tar.gz")
sha256sums=('9607d9d260654eb607c54a8b8c991e4406008605c383ded4f4034522dc0bad7d')

prepare() {
  cp -a latexcodec-$pkgver{,-py2}
}

build() {
  cd "$srcdir/latexcodec-$pkgver"
  python setup.py build

  cd "$srcdir/latexcodec-$pkgver-py2"
  python2 setup.py build
}

check() {
  cd "$srcdir/latexcodec-$pkgver"
  nosetests

  cd "$srcdir/latexcodec-$pkgver-py2"
  nosetests2
}

package_python-latexcodec() {
  depends=('python-six')

  cd "$srcdir/latexcodec-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-latexcodec() {
  depends=('python2-six')

  cd "$srcdir/latexcodec-$pkgver-py2"
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
