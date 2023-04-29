# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Contributor: Grey Christoforo <first name [at] last name [dot] net>

pkgname=python-ijson
pkgver=3.2.0
pkgrel=1
pkgdesc="Iterative JSON parser with Pythonic interface"
arch=(x86_64)
url="https://github.com/ICRAR/ijson"
license=('BSD')
depends=('python' 'yajl')
makedepends=('python-setuptools' 'python-pytest')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ICRAR/ijson/archive/v${pkgver}.tar.gz")
sha256sums=('20e64b3786bc65f45e40e77413fdcd3e3b692ecbd361ef13d2319655f5b66675')

build() {
  cd ijson-$pkgver
  python setup.py build
}

check() {
  cd ijson-$pkgver
  local python_version=$(python -c 'import sys; print(".".join(map(str, sys.version_info[:2])))')
  PYTHONPATH="$PWD/build/lib.linux-$CARCH-${python_version}" pytest
}

package(){
  cd ijson-$pkgver
  python setup.py install --root="$pkgdir/" --optimize=1 --skip-build
  install -m644 -Dt "${pkgdir}/usr/share/licenses/${pkgname}" LICENSE.txt
}

# vim:ts=2:sw=2:et:
