# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python2-monotonic
pkgver=1.3
pkgrel=1
pkgdesc="An implementation of time.monotonic() for Python 2 & < 3.3"
arch=('any')
url='https://pypi.python.org/pypi/monotonic'
license=('Apache')
depends=('python2')
makedepends=('python2-setuptools' 'git')
source=("git+https://github.com/atdt/monotonic#tag=$pkgver")
sha256sums=('SKIP')

package() {
  cd monotonic
  python2 setup.py install --root="$pkgdir" --optimize=1
}

# vim: ts=2 sw=2 et:
