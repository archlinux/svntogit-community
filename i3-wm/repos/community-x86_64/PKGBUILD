# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>

pkgname=i3-wm
pkgver=4.20.1
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
b2sums=('a7943b3bc680eb3df596b008d751d034fc6ccf2b6891db731b9af5164fdcfc2872c0756c81c3f11f94a30aa9bdc4ecf4b47d20022a214bb6eb6c06fd78458fb3'
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
