# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgname=mgard
pkgver=1.0.0
pkgrel=1
pkgdesc="MultiGrid Adaptive Reduction of Data"
arch=(x86_64)
url="https://github.com/CODARcode/MGARD"
license=(Apache)
depends=(blas lapack glibc yaml-cpp zlib zstd)
makedepends=(cmake) # tclap 1.4 required but unreleased
# mgard requires catch2 3.x which is currently unreleased
#checkdepends=(catch2)
source=(${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('2dd153abc9bef7d87923cdefca6243b2050b7522e1d2b196e04c73c5cee6e880')

build() {
  cmake -B build -S ${pkgname^^}-${pkgver} \
    -DCMAKE_INSTALL_PREFIX=/usr
  make -C build
}

check() {
  cd build
  ctest -v --output-on-failure
}

package() {
  make -C build DESTDIR="${pkgdir}" install
  # Uneeded file
  rm "${pkgdir}"/usr/include/mgard/MGARDConfig.hpp.in
}
