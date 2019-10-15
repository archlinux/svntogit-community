# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: TingPing <tingping@tingping.se>

pkgname=hexchat
pkgver=2.14.2
pkgrel=4
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
        '0001-python-backport.patch')
sha256sums=('SKIP'
            'eb2d038dba5f56ddc156fafea41c6560baf09a401ae9ea4f6b8ee079d542fc38')

prepare() {
  cd hexchat
  patch -Np1 < ../0001-python-backport.patch
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
