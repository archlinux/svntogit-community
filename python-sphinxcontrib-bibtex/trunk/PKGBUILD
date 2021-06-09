# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Co-Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

_pkgname=sphinxcontrib-bibtex
pkgname="python-${_pkgname}"
pkgver=2.3.0
pkgrel=1
pkgdesc="A Sphinx extension for BibTeX style citations"
arch=('any')
url="https://sphinxcontrib-bibtex.readthedocs.org"
license=('BSD')
depends=('python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-docutils')
makedepends=('python-setuptools')
checkdepends=('python-pytest')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/mcmtroffaes/${_pkgname}/archive/${pkgver}.tar.gz")
sha256sums=('9898c5374f097e647d6fc7cd08b4779f84f3232caa7cd8f1b49f3b71438e978f')

build() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  PYTHONPATH=".:${PYTHONPATH}" pytest
}

package() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
