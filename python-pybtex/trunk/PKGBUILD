# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex
pkgver=0.23.0
pkgrel=1
pkgdesc="A BibTeX-compatible bibliography processor written in Python"
arch=("any")
url="https://pybtex.org"
license=("GPL")
# Overridden in package_* functions
depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/p/pybtex/pybtex-$pkgver.tar.gz")
sha256sums=('b92be18ccd5e9a37895949dcf359a1f6890246b73646dddf1129178ee12e4bef')

build() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/pybtex-$pkgver"
  pytest
}

package() {
  cd "$srcdir/pybtex-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # Files under site-packages/tests/ conflict with other python packages.
  rm -rf "$pkgdir"/usr/lib/python3.?/site-packages/tests/
}
