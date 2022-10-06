# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>

pkgname=i3-wm
pkgver=4.21
pkgrel=3
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
        '0001-Use-OVER-operator-for-drawing-text.patch'
        "i3-respect-max-border-style.patch::https://github.com/i3/i3/pull/5158.patch")
b2sums=('cf53e0087cb4dabc8eefa8430cc5f7057de927ef49f8172a05c62d690ca60e5d20733da4f3a6230d311bf54a94f117d21665e3d2b39b7f45814e3b0462e12efe'
        'SKIP'
        '35be78fc8be805fa4b7f32c8a18c62a0436f433e9064ef5adf32baa9aa816276da3b53b977287640ab70f30eea14bbd4dc002d49d9149afa01e0706a45dba947'
        'c09956abda0ac9094c459ae6c6c5f2917349f3ed4c3c2e78c981e49ca5541d3e3291e02117cbff7f53f9ad697971e178f60bcc47a5a334cf26330ad5a81eb4db')
validpgpkeys=('424E14D703E7C6D43D9D6F364E7160ED4AC8EE1D') # Michael Stapelberg <michael@stapelberg.de>

prepare() {
  cd i3-$pkgver
  # https://github.com/i3/i3/pull/2925
  patch -Np1 -i ../0001-Use-OVER-operator-for-drawing-text.patch
  # https://github.com/i3/i3/issues/5149
  patch -Np1 -i ../i3-respect-max-border-style.patch
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
