# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.4.8
pkgrel=1
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2' 'libevdev' 'upower')
makedepends=('autoconf-archive' 'python' 'gtk-doc')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz")
b2sums=('a200eba847785ad4a99e229c10574ad99b0874ef14e8b14d5190e12090ae5f4577461743ac1993a1bdb28de85100b509c8affc7ba3426a61b9cba95ea14d2686')

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
