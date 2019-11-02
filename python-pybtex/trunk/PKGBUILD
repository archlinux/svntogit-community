# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgbase=python-pybtex
pkgname=(python-pybtex python2-pybtex)
pkgver=0.22.2
pkgrel=3
pkgdesc="A BibTeX-compatible bibliography processor written in Python"
arch=("any")
url="https://pybtex.org"
license=("GPL")
# Overridden in package_* functions
depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec'
         'python2' 'python2-setuptools' 'python2-six' 'python2-yaml' 'python2-latexcodec')
checkdepends=('python-nose' 'python2-nose')
source=("https://pypi.io/packages/source/p/pybtex/pybtex-$pkgver.tar.gz")
sha256sums=('00816e5f8570609d8ce3360cd23916bd3e50428a3508127578fdb4dc2b731c1c')

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
  cd "$srcdir/pybtex-$pkgver"
  python setup.py nosetests

  cd "$srcdir/pybtex-$pkgver-py2"
  python2 setup.py nosetests
}

package_python-pybtex() {
  depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec')

  cd "$srcdir/pybtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # Files under site-packages/tests/ conflict with other python packages.
  rm -rf "$pkgdir"/usr/lib/python3.?/site-packages/tests/
}

package_python2-pybtex() {
  depends=('python2' 'python2-setuptools' 'python2-six' 'python2-yaml' 'python2-latexcodec')

  cd "$srcdir/pybtex-$pkgver-py2"
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # Files under site-packages/tests/ conflict with other python packages.
  rm -rf "$pkgdir"/usr/lib/python2.?/site-packages/tests/

  # Rename executables to avoid file conflict with python-pybtex
  mv "$pkgdir"/usr/bin/pybtex{,2}
  mv "$pkgdir"/usr/bin/pybtex-format{,2}
  mv "$pkgdir"/usr/bin/pybtex-convert{,2}
}
