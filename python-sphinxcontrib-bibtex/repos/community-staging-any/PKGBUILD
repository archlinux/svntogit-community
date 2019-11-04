# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgname=python-sphinxcontrib-bibtex
pkgver=0.4.2
pkgrel=3
pkgdesc="A Sphinx extension for BibTeX style citations"
arch=('any')
url="https://sphinxcontrib-bibtex.readthedocs.org"
license=('BSD')
depends=('python-six' 'python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-oset')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-sphinx-testing')
source=("https://pypi.io/packages/source/s/sphinxcontrib-bibtex/sphinxcontrib-bibtex-$pkgver.tar.gz")
sha256sums=('169afb3a3485775e5473934a0fdff1780e8bdcdd44db7ed286044a074331c729')

build() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  # Some tests fail because of a warning: https://github.com/mcmtroffaes/sphinxcontrib-bibtex/issues/163
  python setup.py nosetests || warning "Some python3 tests failed"
}

package() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
