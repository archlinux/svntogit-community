# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.13
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('0b4cb41dc1b76d1c0f46655d8b1c56187d2bf18fa12fad9ad6e8acd321a98df372713a92c6649479498bb5939c91ce16a1032ec03afc5a2f7c92cd68882c2bd9')
b2sums=('5db88c9ff9103f2e4b8e15d7dc0d677c3956a85ce5e86e371c4c32a21c3bc219990edd71a20a6b650342eff1068c0ba0976529d62d21dcc17dfc020abf7167ec')

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
