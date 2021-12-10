# Maintainer: Andrzej Giniewicz <gginiu@gmail.com>
# Contributor: Martino Pilia <martino.pilia@gmail.com>
# Contributor: Ben Greiner <code-arch@bnavigator.de>

# TODO: think about including check() after #460 and #469 are fixed upstream

pkgname=python-scikit-build
pkgver=0.12.0
pkgrel=3
pkgdesc="Improved build system generator for CPython C, C++, Cython and Fortran extensions"
arch=('any')
url="https://scikit-build.org"
license=('MIT')
depends=('cmake' 'python-distro' 'python-wheel')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/scikit-build/scikit-build/archive/${pkgver}.tar.gz")
sha256sums=('c32a415d2e7920a4a966b037403c93b02c8a958d8badf3c60abd4b4493f7d988')

build() {
  cd "${srcdir}/scikit-build-${pkgver}"

  python setup.py build_ext --inplace
  python setup.py build
}

package() {
  cd "${srcdir}/scikit-build-${pkgver}"

  python setup.py install --skip-build --root="$pkgdir" --optimize=1

  install -D -m644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
