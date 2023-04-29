# Maintainer : Eli Schwartz <eschwartz@archlinux.org>

pkgname=python-genshi
pkgver=0.7.7
pkgrel=2
pkgdesc="Python toolkit for stream-based generation of output for the web."
arch=('any')
url="https://genshi.edgewall.org/"
license=("BSD")
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/edgewall/genshi/archive/${pkgver}.tar.gz")
sha256sums=('53920c8ed890a3ce0e274845abe82d34736191ffc51300788d4cc71e4fcdd0eb')

build() {
  cd genshi-${pkgver}

  python -m build --wheel --no-isolation
}

check() {
  cd genshi-${pkgver}

  pytest -v
}

package() {
  cd genshi-${pkgver}

  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm644 COPYING "${pkgdir}"/usr/share/licenses/${pkgname}/COPYING
}
