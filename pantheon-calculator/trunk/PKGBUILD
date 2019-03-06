# Maintainer: Maxime Gauduin <alucryd@archlinux.org>

pkgname=pantheon-calculator
pkgver=1.5.1
pkgrel=1
pkgdesc='The Pantheon Calculator'
arch=(x86_64)
url=https://github.com/elementary/calculator
license=(GPL3)
groups=(pantheon)
depends=(
  glib2
  gtk3
  libgranite.so
)
makedepends=(
  git
  intltool
  meson
  vala
)
source=(pantheon-calculator::git+https://github.com/elementary/calculator.git#tag=${pkgver})
sha256sums=(SKIP)

build() {
  arch-meson pantheon-calculator build
  ninja -C build
}

package() {
  DESTDIR="${pkgdir}" ninja -C build install
}

# vim: ts=2 sw=2 et:
