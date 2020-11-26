# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgname=python-pybtex-docutils
pkgver=0.2.2
pkgrel=4
pkgdesc="A docutils backend for pybtex"
arch=("any")
url="https://github.com/mcmtroffaes/pybtex-docutils"
license=("MIT")
depends=('python-six' 'python-docutils' 'python-pybtex')
makedepends=('python-setuptools')
checkdepends=('python-nose')
source=("https://pypi.io/packages/source/p/pybtex-docutils/pybtex-docutils-$pkgver.tar.gz")
sha256sums=('ea90935da188a0f4de2fe6b32930e185c33a0e306154322ccc12e519ebb5fa7d')

build() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py build
}

check() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  export PYTHONPATH="$srcdir/pybtex-docutils-$pkgver"
  nosetests
}

package() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
