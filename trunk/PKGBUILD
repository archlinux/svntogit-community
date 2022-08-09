# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Balló György <ballogyor+arch@gmail.com>

pkgname=bamf
pkgver=0.5.6
pkgrel=1
pkgdesc='Application matching framework'
arch=(x86_64)
url=https://launchpad.net/bamf
license=(GPL)
depends=(
  libgtop
  libwnck3
)
makedepends=(
  git
  gnome-common
  gobject-introspection
  vala
)
_tag=17aef81f0500cbc4333f1f327126adf653826466
source=(git+https://git.launchpad.net/bamf?signed#tag=${_tag})
validpgpkeys=(D4C501DA48EB797A081750939449C2F50996635F) # Marco Trevisan (Treviño) <mail@3v1n0.net>
b2sums=(SKIP)

pkgver() {
  cd bamf
  git describe --tags
}

prepare() {
  cd bamf
  NOCONFIGURE=1 ./autogen.sh
}

build() {
  cd bamf
  ./configure \
    --prefix=/usr \
    --libexecdir=/usr/lib \
    --localstatedir=/var \
    --sysconfdir=/etc \
    --enable-gtk-doc
  sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
  make
}

package() {
  make DESTDIR="${pkgdir}" -C bamf install
}

# vim: ts=2 sw=2 et:
