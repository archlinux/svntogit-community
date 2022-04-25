# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Llewelyn Trahaearn <WoefulDerelict at GMail dot com>
# Contributor: Yurii Kolesnykov <yurikoles at gmail dot com>
# Contributor: Gustavo <sl1pkn07 at gmail dot com>
# Contributor: Maxime Gauduin <alucryd at archlinux dot org>
# Contributor: Balló György <ballogyor+arch at gmail dot com>

pkgbase=libindicator
pkgname=("${pkgbase}-gtk"{2,3})
pkgver=12.10.1
pkgrel=10
pkgdesc='Set of symbols and convenience functions for Ayatana indicators'
url='https://launchpad.net/libindicator'
arch=('x86_64')
license=('GPL3')
makedepends=('gtk2' 'gtk3' 'python')
source=(https://launchpad.net/${pkgbase}/${pkgver%.*}/${pkgver}/+download/${pkgbase}-${pkgver}.tar.gz{,.asc})
sha512sums=('d6d77d0309b15cf6b52539323920ab0c1594cb1c1cef8a8d67cd0f76f8ceeeac28eb6db6227563df1932e6f1fadcffac68d82982182b745257dfaf91f1c945af'
            'SKIP')
validpgpkeys=('6FC05581A37D71FCECE165DB5BE41E162CD6358E')  # Charles Kerr <charles.kerr@canonical.com>

prepare() {
  (cd ${pkgbase}-${pkgver}
    sed -i 's/-Werror//' {libindicator,tools}/Makefile.am
    autoreconf -fi
  )
  cp -ra ${pkgbase}-${pkgver}{,-gtk2}
}

build() {
  msg2 "Building gtk3..."
  (cd ${pkgbase}-${pkgver}
    ./configure \
      --prefix=/usr \
      --localstatedir=/var \
      --libexecdir=/usr/lib/libindicator \
      --sysconfdir=/etc \
      --with-gtk=3 \
      --disable-static \
      --disable-tests
    sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
    make
  )

  msg2 "Building gtk2..."
  (cd ${pkgbase}-${pkgver}-gtk2
    ./configure \
      --prefix=/usr \
      --localstatedir=/var \
      --libexecdir=/usr/lib/libindicator \
      --sysconfdir=/etc \
      --with-gtk=2 \
      --disable-static \
      --disable-tests
    sed -i -e 's/ -shared / -Wl,-O1,--as-needed\0/g' libtool
    make
  )
}

package_libindicator-gtk2() {
  pkgdesc+=" (GTK+ 2 library)"
  depends=('gtk2')

  cd ${pkgbase}-${pkgver}-gtk2
  make DESTDIR="${pkgdir}" install
  rm -rf "${pkgdir}"/usr/share
}

package_libindicator-gtk3() {
  pkgdesc+=" (GTK+ 3 library)"
  depends=('gtk3')

  cd ${pkgbase}-${pkgver}
  make DESTDIR="${pkgdir}" install
  rm -rf "${pkgdir}"/usr/share
}

# vim: ts=2 sw=2 et:
