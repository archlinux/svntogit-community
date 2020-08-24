# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: xduugu

pkgname=patchelf
pkgver=0.11
pkgrel=1
pkgdesc='Small utility to modify the dynamic linker and RPATH of ELF executables'
url='https://nixos.org/patchelf.html'
arch=('x86_64')
license=('GPL3')
depends=('gcc-libs')
source=(https://github.com/NixOS/patchelf/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('b156bad513d5bac33aaf61d5f04d5a78efc81abf8c0ccb851f605e1137c21e671b4933263a47543daf5064db5e83c9afa836b1aea143fca7d8e6a18ebf96beb8')
b2sums=('f8b0fb897b0a7bf905a10c6559cc801291b0b15a26a2efe0789b2b2f26d6d827b6f633a2b35059345908afb6e8c8a3ff5b4667a9161355f9a14dee84b6400f28')

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
