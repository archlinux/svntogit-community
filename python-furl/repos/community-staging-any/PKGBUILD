# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Husam Bilal <husam212 AT gmail DOT com>

_name=furl
pkgname=python-furl
pkgver=2.1.3
pkgrel=4
pkgdesc="A small Python library that makes parsing and manipulating URLs easy"
url="https://github.com/gruns/furl"
depends=('python-orderedmultidict' 'python-six')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
license=('Unlicense')
arch=('any')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('ce7455bd1a352243efd9715e80e9f9979631cc058927edcd8c52ccb85d27fd8f32079611bb29c487d2add2d1d941d56e4db75520339dc371b1539811ccefda02')
b2sums=('128d43464f75032f726d6408ee7d0c715b617846798ff80c43c91bac025c943492b0ca4f7271b6989d1a73db8948a313aab2930a8f6ed81d62e7b03e984e6f3d')

build() {
  cd "${_name}-${pkgver}"
  python setup.py build
}

check() {
  cd "${_name}-${pkgver}"
  export PYTHONPATH="build:${PYTHONPATH}"
  pytest -v
}

package() {
  cd "${_name}-${pkgver}"
  python setup.py install --optimize=1 --root="${pkgdir}"
  install -vDm 644 LICENSE.md -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -vDm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}
