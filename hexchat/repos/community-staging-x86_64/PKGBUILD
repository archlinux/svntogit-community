# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: TingPing <tingping@tingping.se>

pkgname=hexchat
pkgver=2.14.3
pkgrel=3
pkgdesc='A popular and easy to use graphical IRC (chat) client'
arch=('x86_64')
url='https://hexchat.github.io/'
license=('GPL')
depends=('dbus-glib' 'desktop-file-utils' 'gdk-pixbuf2' 'glib2' 'gtk2'
         'libcanberra' 'libnotify' 'libproxy' 'openssl' 'pango' 'pciutils')
makedepends=('git' 'intltool' 'iso-codes' 'lua' 'meson' 'perl' 'python-cffi')
optdepends=('enchant: Spell check'
            'iso-codes: Display language names instead of codes'
            'lua: Lua plugin'
            'perl: Perl plugin'
            'python-cffi: Python plugin')
source=("git+https://github.com/hexchat/hexchat.git#tag=v${pkgver}"
        '0002-python-3-8.patch')
sha256sums=('SKIP'
            '8d17ce657e744272815b5fb33d8ad959f79ece3294349637eaadcf86d90496fa')

prepare() {
  cd hexchat
  patch -Np1 < ../0002-python-3-8.patch
}

build() {
  arch-meson hexchat build \
    -Dwith-lua='lua' \
    -Dwith-text='true'
  ninja -C build
}

package() {
  DESTDIR="${pkgdir}" ninja -C build install
}

# vim: ts=2 sw=2 et:
