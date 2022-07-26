# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.15.0
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('3b2d3d6458be5b2d43cd2878dfb1a185a95cc13cd4c94abd0ee79979afb36f46e347acc292b8d9c2954a342b7291774e6a1b63930e9f90a1cf4179ec075ab046')
b2sums=('08fc2cffd7d9e835c01c828c16762fb0b3c3e422990f2d0028a65a3e0ec849d01bdef699b6f68afa6bf307e34f5e76121fc94460793c95c055552e1d8a68d772')

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
