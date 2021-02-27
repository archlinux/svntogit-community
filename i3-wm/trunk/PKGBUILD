# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>

pkgname=i3-wm
pkgver=4.19.2
pkgrel=1
pkgdesc='Improved dynamic tiling window manager'
arch=('x86_64')
url=https://i3wm.org
license=('BSD')
groups=('i3')
depends=('libev' 'libxkbcommon-x11' 'pango' 'startup-notification'
         'xcb-util-cursor' 'xcb-util-keysyms' 'xcb-util-wm' 'xcb-util-xrm'
         'yajl')
makedepends=('meson' 'xmlto')
optdepends=('dmenu: for the default program launcher'
            'rofi: for a modern dmenu replacement'
            'i3lock: for the default screen locker'
            'xss-lock: for the default screen locker'
            'i3status: for the default status bar generator'
            'perl: for i3-save-tree and i3-dmenu-desktop'
            'perl-anyevent-i3: for i3-save-tree'
            'perl-json-xs: for i3-save-tree')
replaces=('i3' 'i3bar')
backup=('etc/i3/config')
source=("$url/downloads/i3-$pkgver.tar.xz"{,.asc}
        '0001-Use-OVER-operator-for-drawing-text.patch')
b2sums=('28d4dba50ae30cb620dcbd759e0ba29e284071234261aca2a217b6eef9194f72eca67d3632dc1e6a9b9879925e55c18b7a42676eaed41dd1354f772e48309d45'
        'SKIP'
        '35be78fc8be805fa4b7f32c8a18c62a0436f433e9064ef5adf32baa9aa816276da3b53b977287640ab70f30eea14bbd4dc002d49d9149afa01e0706a45dba947')
validpgpkeys=('424E14D703E7C6D43D9D6F364E7160ED4AC8EE1D') # Michael Stapelberg <michael@stapelberg.de>

prepare() {
  cd i3-$pkgver
  # https://github.com/i3/i3/pull/2925
  patch -Np1 -i ../0001-Use-OVER-operator-for-drawing-text.patch
}

build() {
  cd i3-$pkgver
  arch-meson build
  ninja -C build
}

package() {
  cd i3-$pkgver
  DESTDIR="$pkgdir" ninja -C build install
  install -Dm644 -t "$pkgdir"/usr/share/licenses/$pkgname LICENSE
}

# vim:set ts=2 sw=2 et:
