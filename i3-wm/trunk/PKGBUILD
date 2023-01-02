# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Maintainer: T.J. Townsend <blakkheim@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Jelle van der Waa <jelle@vdwaa.nl>

pkgname=i3-wm
pkgver=4.22
pkgrel=2
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
replaces=('i3' 'i3bar' 'i3-gaps')
provides=('i3-gaps')
backup=('etc/i3/config')
options=('debug')
source=("$url/downloads/i3-$pkgver.tar.xz"{,.asc})
b2sums=('fa179f445ba4286bfeec98dc7a2e1dfad14bda6874e84878a48ee5890ed4cf3a90fc542e8e14aedaaba3abebc8d280284a3b00e838da70a783064a4bd271ca41'
        'SKIP')
validpgpkeys=('424E14D703E7C6D43D9D6F364E7160ED4AC8EE1D') # Michael Stapelberg <michael@stapelberg.de>

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
