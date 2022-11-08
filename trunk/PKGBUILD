# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.17.0
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('0db2294cc16a919a84a1bb71194b3ed7a87bb669f684e4cc0943b33899d69690097c59d5c9f8e631bc1b4136db7f10f7cb0fbb1c96912aee567a0fd7dc9c9588')
b2sums=('ef32baae1d1e07c77442878977693849e2dd3d5c1c1b8d53eb54ee7b1b78eb77ebcf87cbd7caa683f0043e6d7b90ca2593968e9c95b0902e45c4634823be196b')

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
