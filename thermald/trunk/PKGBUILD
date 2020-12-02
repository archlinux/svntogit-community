# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.4.1
pkgrel=1
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2' 'libevdev' 'upower')
makedepends=('autoconf-archive' 'python' 'gtk-doc')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz"
        'modules-load-thermald.conf')
b2sums=('ee4d6bc590bc50639c0b19adbba7e243358174a837b2ff155dea060b1cd09171d4fb77b18b785dc9f64a633f680358cb1d7b36e3bd438e5267e0a0a27e18497e'
        '70cdf39afbcc4ea6b0cbe59182714a18755bad8e742f69f9b08e1415dd8f77e00473b9808c46dec3de4e0b5ec17f0bc16d0bd54d61b1e8e77e27901d90aedceb')

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
  install -Dm644 "${srcdir}"/modules-load-thermald.conf "${pkgdir}"/usr/lib/modules-load.d/thermald.conf
}
