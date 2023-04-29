# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Co-Maintainer: Baptiste Jonglez <archlinux at bitsofnetworks dot org>
# Contributor: Patrice Peterson <runiq at archlinux dot us>

_pkgname=sphinxcontrib-bibtex
pkgname="python-${_pkgname}"
pkgver=2.5.0
pkgrel=2
pkgdesc="A Sphinx extension for BibTeX style citations"
arch=('any')
url="https://sphinxcontrib-bibtex.readthedocs.org"
license=('BSD')
depends=('python-sphinx' 'python-pybtex' 'python-pybtex-docutils' 'python-docutils')
makedepends=('python-setuptools-scm' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest' 'python-pytest-cov' 'python-numpydoc')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/mcmtroffaes/${_pkgname}/archive/${pkgver}.tar.gz")
b2sums=('9018b99064ac02efabcf9a0470a04c62ae7fa3d6e17f919e06249c5c882f85b1324e40e88f2491f0a9547e7a40a0183a56757c51a29a609f9dd93a3df00990f5')

build() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python -m build --wheel --no-isolation
}

check() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  PYTHONPATH="${PWD}/build/lib:${PWD}/src:${PYTHONPATH}" pytest -k 'not test_citation_rinoh'
}

package() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm644 LICENSE.rst "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
