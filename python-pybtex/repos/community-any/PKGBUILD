# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex
pkgver=0.22.2
pkgrel=3
pkgdesc="A BibTeX-compatible bibliography processor written in Python"
arch=("any")
url="https://pybtex.org"
license=("GPL")
# Overridden in package_* functions
depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec')
checkdepends=('python-nose')
source=("https://pypi.io/packages/source/p/pybtex/pybtex-$pkgver.tar.gz")
sha256sums=('00816e5f8570609d8ce3360cd23916bd3e50428a3508127578fdb4dc2b731c1c')

build() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py nosetests
}

package() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # Files under site-packages/tests/ conflict with other python packages.
  rm -rf "$pkgdir"/usr/lib/python3.?/site-packages/tests/
}
