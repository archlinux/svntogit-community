# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Contributor: Husam Bilal <husam212 AT gmail DOT com>

_name=infinity
pkgname="python-${_name}"
pkgver=1.5
pkgrel=6
pkgdesc='All-in-one infinity value for Python. Can be compared to any object.'
url='https://github.com/kvesteri/infinity'
depends=('python')
checkdepends=('python-pytest')
makedepends=('python-setuptools')
license=('BSD')
arch=('any')
source=("https://pypi.python.org/packages/source/i/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('d61c16fe08749dab050ffb17f8cb392b22ef0c409d736625820419859a0533e067d04a3244e937cf968b40eb02d6bcecb0f80525797dc372eba7205836bad9cb')

build() {
  cd "${srcdir}/${_name}-${pkgver}"
  python setup.py build
}

check() {
  cd "${srcdir}/${_name}-${pkgver}"
  py.test .
}

package() {
  cd "${srcdir}/${_name}-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
