# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.9
pkgrel=3
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/NixOS/patchelf/archive/${pkgver}.tar.gz)
sha512sums=('70e615f2f705f413aab5e3eebe20ffe79743bb92381b10a8faa49f16ca24b0f9bd4095c5644f682ec94d75012ffb1b39837933faa9f3c1f1c41bdc5b9d010a30')

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
