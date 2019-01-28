# Maintainer: Thorsten Töpper <atsutane-tu@freethoughts.de>

pkgname=i3-wm
pkgver=4.16.1
pkgrel=1
pkgdesc="An improved dynamic tiling window manager"
url="https://i3wm.org/"
arch=(x86_64)
license=(BSD)
depends=(xcb-util-cursor xcb-util-keysyms xcb-util-wm xcb-util-xrm libev yajl startup-notification
         pango libxkbcommon-x11)
makedepends=(bison flex asciidoc xmlto)
optdepends=('dmenu: As menu.'
            'i3lock: For locking your screen.'
            'i3status: To display systeminformation with a bar.'
            'perl: i3-save-tree and i3-dmenu-desktop'
            'perl-anyevent-i3: Features like saving the layout.'
            'perl-json-xs: Features like saving the layout.')
backup=(etc/i3/config)
groups=(i3)
replaces=(i3 i3bar)
source=("https://i3wm.org/downloads/i3-$pkgver.tar.bz2"{,.asc}
        0001-Use-OVER-operator-for-drawing-text.patch)
sha256sums=('ab65c25c06acbdc67cba3ff23e2a82ea17911def65f4fd0200bb6f9382378576'
            'SKIP'
            'e49e147b1cd06f95188decbbe41f5c3a0aca18d0195750bc3ea16465b4aca563')
validpgpkeys=('424E14D703E7C6D43D9D6F364E7160ED4AC8EE1D') # Michael Stapelberg

prepare() {
  mkdir build
  cd i3-$pkgver

  # https://github.com/i3/i3/pull/2925
  patch -Np1 -i ../0001-Use-OVER-operator-for-drawing-text.patch

  autoreconf -fvi
}

build() {
  cd build
  ../i3-$pkgver/configure --prefix=/usr --sysconfdir=/etc
  make
}

package() {
  cd build
  make DESTDIR="$pkgdir" install
  install -Dt "$pkgdir/usr/share/man/man1" -m644 man/*.1
  install -Dt "$pkgdir/usr/share/licenses/$pkgname" -m644 ../i3-$pkgver/LICENSE
}

# vim:set ts=2 sw=2 et:
