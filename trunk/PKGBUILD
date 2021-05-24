# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: TingPing <tingping@tingping.se>

pkgname=hexchat
pkgver=2.14.3
pkgrel=8
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
        '0001-python-cffi.patch'
        '0002-python-3-8.patch'
        '0003-Use-pango_font_metrics_get_height-to-calculate-font-height.patch'
        '0004-fix_segfault_on_lua_pop_with_Lua_5.4.3.patch')
sha256sums=('SKIP'
            '92af0d106627c9b9716036ce81f697de35f37b4ba2e7bd34244824520e485bba'
            '8d17ce657e744272815b5fb33d8ad959f79ece3294349637eaadcf86d90496fa'
            '691f344479a8b1186008516f0ebe7e3d482059cd297f58573634fa5a58f3d0ca'
            'a8d6917deec758b3a822471316f0bd7819d3661ef6f657c52953711227a2cbe6')

prepare() {
  cd hexchat
  patch -Np1 < ../0001-python-cffi.patch
  patch -Np1 < ../0002-python-3-8.patch
  patch -Np1 < ../0003-Use-pango_font_metrics_get_height-to-calculate-font-height.patch
  patch -Np1 < ../0004-fix_segfault_on_lua_pop_with_Lua_5.4.3.patch
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
