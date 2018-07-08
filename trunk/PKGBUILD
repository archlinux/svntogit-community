# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgbase=python-pybtex
pkgname=(python-pybtex python2-pybtex)
pkgver=0.21
pkgrel=4
pkgdesc="A BibTeX-compatible bibliography processor written in Python"
arch=("any")
url="https://pybtex.org"
license=("GPL")
depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec'
         'python2' 'python2-setuptools' 'python2-six' 'python2-yaml' 'python2-latexcodec')
checkdepends=('python-nose' 'python2-nose')
source=("https://pypi.io/packages/source/p/pybtex/pybtex-$pkgver.tar.gz")
sha256sums=('af8a6c7c74954ad305553b118d2757f68bc77c5dd5d5de2cc1fd16db90046000')

prepare() {
  cp -a pybtex-$pkgver{,-py2}
}

build() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py build

  cd "$srcdir/pybtex-$pkgver-py2"
  python2 setup.py build
}

check() {
  cd "$srcdir/pybtex-$pkgver/build/lib"
  export PYTHONPATH="$srcdir/pybtex-$pkgver/build/lib"
  nosetests || warning "Some python3 tests failed"

  cd "$srcdir/pybtex-$pkgver-py2"
  export PYTHONPATH="$srcdir/pybtex-$pkgver-py2"
  nosetests2 || warning "Some python2 tests failed"
}

package_python-pybtex() {
  depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec')

  cd "$srcdir/pybtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

package_python2-pybtex() {
  depends=('python2' 'python2-setuptools' 'python2-six' 'python2-yaml' 'python2-latexcodec')

  cd "$srcdir/pybtex-$pkgver-py2"
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # Rename executables to avoid file conflict with python-pybtex
  mv "$pkgdir"/usr/bin/pybtex{,2}
  mv "$pkgdir"/usr/bin/pybtex-format{,2}
  mv "$pkgdir"/usr/bin/pybtex-convert{,2}
}
