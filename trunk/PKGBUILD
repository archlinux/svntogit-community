# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.4.7
pkgrel=1
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2' 'libevdev' 'upower')
makedepends=('autoconf-archive' 'python' 'gtk-doc')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz")
b2sums=('2c546175181383c21d95345e4884e5d476a47b2c5f2e1dc379add5c340bd9f421567b7c391b6002e05e3ad793ba2f563d2eca7913f0688b53a8565f52da58fbf')

build() {
  cd ${_pkgname}-${pkgver}
  ./autogen.sh
  ./configure \
    --prefix=/usr \
    --sysconfdir=/etc \
    --with-dbus-sys-dir=/usr/share/dbus-1/system.d \
    --localstatedir=/var \
    --sbindir=/usr/bin
  make
}

package() {
  cd ${_pkgname}-${pkgver}
  DESTDIR="${pkgdir}" make install
}
