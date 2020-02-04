# Maintainer: Andrzej Giniewicz <gginiu@gmail.com>
# Contributor: Martino Pilia <martino.pilia@gmail.com>
# Contributor: Ben Greiner <code-arch@bnavigator.de>

# TODO: think about including check() after #460 and #469 are fixed upstream

pkgname=python-scikit-build
pkgver=0.10.0
pkgrel=3
pkgdesc="Improved build system generator for CPython C, C++, Cython and Fortran extensions"
arch=('any')
url="https://scikit-build.org"
license=('MIT')
depends=('cmake' 'python-distro' 'python-wheel')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/scikit-build/scikit-build/archive/${pkgver}.tar.gz"
        "issue458.patch")
sha256sums=('2beec252813b20327072c15e9d997f15972aedcc6a130d0154979ff0fdb1b010'
            '4e1ebdef1fc08763772c767ebad2f7fee2513cad084af318a96647c458937eeb')

prepare() {
  cd "${srcdir}/scikit-build-${pkgver}"

  # see https://github.com/scikit-build/scikit-build/pull/458
  patch -p1 < ../issue458.patch
}

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
