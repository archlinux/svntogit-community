# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex
pkgver=0.24.0
pkgrel=1
pkgdesc="A BibTeX-compatible bibliography processor written in Python"
arch=("any")
url="https://pybtex.org"
license=("GPL")
# Overridden in package_* functions
makedepends=('python-setuptools')
depends=('python' 'python-setuptools' 'python-six' 'python-yaml' 'python-latexcodec')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/p/pybtex/pybtex-$pkgver.tar.gz")
sha256sums=('818eae35b61733e5c007c3fcd2cfb75ed1bc8b4173c1f70b56cc4c0802d34755')

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
