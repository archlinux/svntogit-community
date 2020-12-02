# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Co-Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgname=python-sphinxcontrib-bibtex
pkgver=1.0.0
pkgrel=3
pkgdesc="A Sphinx extension for BibTeX style citations"
arch=('any')
url="https://sphinxcontrib-bibtex.readthedocs.org"
license=('BSD')
depends=('python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-oset')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-sphinx-testing' 'python-coverage')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/mcmtroffaes/sphinxcontrib-bibtex/archive/1.0.0.tar.gz")
sha256sums=('964798058d91783bdd358c68e9f3a4e214a075dca91f8d91637f09ac467130d8')

build() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  # Some tests fail because of a warning: https://github.com/mcmtroffaes/sphinxcontrib-bibtex/issues/163
  local MY_YELLOW='\033[1;33m'
  local MY_NOCOLOUR='\033[0m'
  python setup.py nosetests || echo -e "${MY_YELLOW}WARNING: Some python3 tests failed!\n(https://github.com/mcmtroffaes/sphinxcontrib-bibtex/issues/163)${MY_NOCOLOUR}"
}

package() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
