# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.14.3
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('2f5caa6b038e630896dc0cebaf4d6f88d91f6dee7f2ffa2fc6b90d199b3a0140b7fe39ea43e582f7ac1145309a61e11fb7ce36c579ad217c48f1b189738f79c8')
b2sums=('ca9c28c88ff6a5eb37a8cb9010642f04335b74e2132987f34bc167c140dc95cd4ac7a3ed71b7287d952a0201b12148a15f3066e5c7d3d453cc18a1e97b6283ed')

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
