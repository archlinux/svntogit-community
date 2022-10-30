# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.16.0
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('3f39e6fa9a8cba246fd2f5fb6bddc4281e672988e3f9f8772aa0cfb45232c5aca6ab1ea5d1b3b8fc2b2ae0e865f1b7d53f4d47f5d7608c8fa039da019077f559')
b2sums=('84b28f297d1f66e9a4849f10fd660e1089a7aebdd15799cc7e5c4df46d4aca759cc8c87210c548fc7f80c39a48360695ff1d78090b635dd7188d8d511fb72cea')

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
