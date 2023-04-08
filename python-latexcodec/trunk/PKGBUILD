# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

_pkgname=latexcodec
pkgname=python-${_pkgname}
pkgver=2.0.1
pkgrel=6
pkgdesc="A lexer and codec to work with LaTeX code in Python"
arch=('any')
url="https://github.com/mcmtroffaes/latexcodec"
license=('MIT')
depends=('python-six')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-pytest')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/mcmtroffaes/${_pkgname}/archive/${pkgver}.tar.gz")
sha256sums=('eda36ddfc969f86c9a8fdd50c12b484fa42dbfa33b84422144643b60081ca022')

build() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  nosetests
}

package() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
