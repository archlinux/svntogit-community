# Maintainer : Daniel Bermond <dbermond@archlinux.org>
# Maintainer : Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Simon Boulay <simon.boulay@alkeona.net>

pkgname=python-breathe
pkgver=4.35.0
pkgrel=2
pkgdesc="An extension to reStructuredText and Sphinx to be able to read and render Doxygen xml output"
arch=('any')
url="https://breathe.readthedocs.org/en/latest/"
license=('BSD')
depends=('python' 'python-docutils' 'python-sphinx')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
checkdepends=('python-pytest')
source=("https://github.com/michaeljones/breathe/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz"
        "${pkgname}-${pkgver}.tar.gz.sig"::"https://github.com/michaeljones/breathe/releases/download/v${pkgver}/breathe-${pkgver}.tar.gz.sig")
sha512sums=('76e36fceb89c21e2c62471a37b856f8e7077f946ca8ebffdd068297d7d447ba4f42f8f9d91e231f7a181d7dba2cb8650479f35f8bef342184e5ccbd3dd951f91'
            'SKIP')
validpgpkeys=('8AED58021FEACDD5F27BA0E6A72F627716EA9D96') # Melvin Vermeeren <vermeeren@vermwa.re>

build() {
  cd "breathe-${pkgver}"
  python -m build --wheel --no-isolation
}

check() {
  cd "breathe-${pkgver}"
  PYTHONPATH="$PWD" pytest
}

package_python-breathe() {
  python -m installer --destdir="$pkgdir" "breathe-${pkgver}/dist"/*.whl
  install -D -m644 "breathe-${pkgver}/LICENSE" -t "${pkgdir}/usr/share/licenses/${pkgname}"
}
