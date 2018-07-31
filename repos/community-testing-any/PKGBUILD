# Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Immae

pkgbase=python-pybtex-docutils
pkgname=(python-pybtex-docutils python2-pybtex-docutils)
pkgver=0.2.1
pkgrel=2
pkgdesc="A docutils backend for pybtex"
arch=("any")
url="https://github.com/mcmtroffaes/pybtex-docutils"
license=("MIT")
depends=('python-six' 'python-docutils' 'python-pybtex'
         'python2-six' 'python2-docutils' 'python2-pybtex')
makedepends=('python-setuptools' 'python2-setuptools')
checkdepends=('python-nose' 'python2-nose')
source=("https://pypi.io/packages/source/p/pybtex-docutils/pybtex-docutils-$pkgver.tar.gz")
sha256sums=('e4b075641c1d68a3e98a6d73ad3d029293fcf9e0773512315ef9c8482f251337')

prepare() {
  cp -a pybtex-docutils-$pkgver{,-py2}
}

build() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py build

  cd "$srcdir/pybtex-docutils-$pkgver-py2"
  python2 setup.py build
}

check() {
  cd "$srcdir/pybtex-docutils-$pkgver"
  export PYTHONPATH="$srcdir/pybtex-docutils-$pkgver"
  nosetests

  cd "$srcdir/pybtex-docutils-$pkgver-py2"
  export PYTHONPATH="$srcdir/pybtex-docutils-$pkgver-py2"
  nosetests2
}

package_python-pybtex-docutils() {
  depends=('python-six' 'python-docutils' 'python-pybtex')

  cd "$srcdir/pybtex-docutils-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-pybtex-docutils() {
  depends=('python2-six' 'python2-docutils' 'python2-pybtex')

  cd "$srcdir/pybtex-docutils-$pkgver-py2"
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
