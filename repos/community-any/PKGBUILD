# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgbase=python-sphinxcontrib-bibtex
pkgname=(python-sphinxcontrib-bibtex python2-sphinxcontrib-bibtex)
pkgver=0.4.0
pkgrel=2
pkgdesc="A Sphinx extension for BibTeX style citations"
arch=('any')
url="http://sphinxcontrib-bibtex.readthedocs.org"
license=('BSD')
depends=('python-six' 'python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-oset'
         'python2-six' 'python2-sphinx' 'python2-pybtex' 'python2-pybtex-docutils' 'python2-oset')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-nose' 'python-sphinx-testing'
              'python2-nose' 'python2-sphinx-testing')
source=("https://pypi.io/packages/source/s/sphinxcontrib-bibtex/sphinxcontrib-bibtex-$pkgver.tar.gz")
sha256sums=('cb9fb4526642fc080204fccd5cd8f41e9e95387278e17b1d6969b1e27c2d3e0c')

prepare() {
  cp -a sphinxcontrib-bibtex-$pkgver{,-py2}
}

build() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py build

  cd "$srcdir/sphinxcontrib-bibtex-$pkgver-py2"
  python2 setup.py build
}

check() {
  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py nosetests || warning "Some python3 tests failed"

  cd "$srcdir/sphinxcontrib-bibtex-$pkgver-py2"
  python2 setup.py nosetests || warning "Some python2 tests failed"
}

package_python-sphinxcontrib-bibtex() {
  depends=('python-six' 'python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-oset')

  cd "$srcdir/sphinxcontrib-bibtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-sphinxcontrib-bibtex() {
  depends=('python2-six' 'python2-sphinx' 'python2-pybtex' 'python2-pybtex-docutils' 'python2-oset')

  cd "$srcdir/sphinxcontrib-bibtex-$pkgver-py2"
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
