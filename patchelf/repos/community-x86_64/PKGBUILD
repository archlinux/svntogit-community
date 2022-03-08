# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.14.5
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('1b7eca84f6fe2d6f6d4469ca1ccdf35dc920d2052ba94b7daeba6c8cb41fdaff20b1e5bac7c8a7650ff12bf4156da87f84d32e75b09958636dc992a1b7b1a59d')
b2sums=('f2e02fb468db7c8c0c4270c7f95ea6c8dc6ffab7ddb0a6479bd5d1dd0481cbc55982af21a13f42076504417264a11e74d50a9f15d3d5735e47019001abf33e41')

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
