# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgname=libaec
pkgver=1.0.6
pkgrel=1
pkgdesc="Adaptive Entropy Coding library"
arch=(x86_64)
url="https://gitlab.dkrz.de/k202009/libaec"
license=(custom)
depends=(glibc)
makedepends=(cmake)
source=(${url}/-/archive/v${pkgver}/${pkgname}-v${pkgver}.tar.bz2)
sha256sums=('31fb65b31e835e1a0f3b682d64920957b6e4407ee5bbf42ca49549438795a288')

build() {
  cmake -B build -S ${pkgname}-v${pkgver} \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_LIBDIR=lib \
    -DCMAKE_BUILD_TYPE=Release
  make -C build
}

package() {
  make -C build DESTDIR="${pkgdir}" install
  install -Dm644 ${pkgname}-v${pkgver}/LICENSE.txt -t "${pkgdir}"/usr/share/licenses/${pkgname}/
  mv "${pkgdir}"/usr/{,lib}/cmake
}
