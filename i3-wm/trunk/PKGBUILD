# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Maintainer: T.J. Townsend <blakkheim@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Jelle van der Waa <jelle@vdwaa.nl>

pkgname=i3-wm
pkgver=4.21.1
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
options=('debug')
source=("$url/downloads/i3-$pkgver.tar.xz"{,.asc}
        '0001-Use-OVER-operator-for-drawing-text.patch')
b2sums=('44661bd9edf0bee384b8be88cbf2361bb2ad26fdbaee9a2e010ebdee662b31129057a1a183f46bef0839a545f63c70d00903b0ec4693c1bc9390c84d7a78ac44'
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
