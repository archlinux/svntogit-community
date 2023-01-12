# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.17.2
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('e5545416d32248d023759457d0a5cd4841d69f39366eb0aa9cfd8a43d2ce372c6e05995bf60ba62bd85c6d98fdece2dbd1e20872e338ef5ac75f11b82ae091b3')
b2sums=('7ed684c63955a0b9cfe293fb966f7f08a90c76e8efb2b493eaf3705c57767b31b31e48ab59f39ff1d91b7a4501e6d203e32a40040625a44a7d44113b1320530c')

prepare() {
  cd ${pkgname}-${pkgver}
  autoreconf -fiv
}

build() {
  cd ${pkgname}-${pkgver}
  ./configure --prefix=/usr
  make
}

check() {
  cd ${pkgname}-${pkgver}
  make -C tests -j1 check
}

package() {
  cd ${pkgname}-${pkgver}
  make DESTDIR="${pkgdir}" install
}

# vim: ts=2 sw=2 et:
