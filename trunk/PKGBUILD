# Maintainer: Levente Polyak <anthraxx@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Maintainer: T.J. Townsend <blakkheim@archlinux.org>
# Contributor: Thorsten Töpper <atsutane-tu@freethoughts.de>
# Contributor: Jelle van der Waa <jelle@vdwaa.nl>

pkgname=i3-wm
pkgver=4.22
pkgrel=4
pkgdesc='Improved dynamic tiling window manager'
arch=('x86_64')
url=https://i3wm.org
license=('BSD')
groups=('i3')
depends=('libev' 'libxkbcommon-x11' 'pango' 'startup-notification' 'ttf-font'
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
source=("$url/downloads/i3-$pkgver.tar.xz"{,.asc}
        'i3-commit-9c8746c0.patch::https://github.com/i3/i3/commit/9c8746c00fee18561e2a0a039d9b1c7387b848c5.patch')
b2sums=('fa179f445ba4286bfeec98dc7a2e1dfad14bda6874e84878a48ee5890ed4cf3a90fc542e8e14aedaaba3abebc8d280284a3b00e838da70a783064a4bd271ca41'
        'SKIP'
        'a304a73ac943cf7b2de00e0d52a4d6c659333760549fe470bf4a2f964eec7ab2d6ecd20e2c4304e83ae0c9caf322430a38dfc63f8a48b1126bc1ebc0d98d76cd')
validpgpkeys=('424E14D703E7C6D43D9D6F364E7160ED4AC8EE1D') # Michael Stapelberg <michael@stapelberg.de>

prepare() {
  cd i3-$pkgver
  patch -Np1 -i ../i3-commit-9c8746c0.patch
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
