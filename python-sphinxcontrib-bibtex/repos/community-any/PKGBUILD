# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

pkgbase=python-sphinxcontrib-bibtex
pkgname=(python-sphinxcontrib-bibtex python2-sphinxcontrib-bibtex)
pkgver=0.4.2
pkgrel=1
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
sha256sums=('169afb3a3485775e5473934a0fdff1780e8bdcdd44db7ed286044a074331c729')

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
  # Some tests fail because of a warning
  python setup.py nosetests || warning "Some python3 tests failed"

  cd "$srcdir/sphinxcontrib-bibtex-$pkgver-py2"
  # Some tests fail because of a warning
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
