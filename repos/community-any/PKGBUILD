# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex-docutils
pkgver=1.0.0
pkgrel=1
pkgdesc="A docutils backend for pybtex"
arch=("any")
url="https://github.com/mcmtroffaes/pybtex-docutils"
license=("MIT")
depends=('python-six' 'python-docutils' 'python-pybtex')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("https://pypi.io/packages/source/p/pybtex-docutils/pybtex-docutils-$pkgver.tar.gz")
sha256sums=('cead6554b4af99c287dd29f38b1fa152c9542f56a51cb6cbc3997c95b2725b2e')

build() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  export PYTHONPATH="$srcdir/pybtex-docutils-$pkgver"
  pytest
}

package() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
