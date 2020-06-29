# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.2
pkgrel=2
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2')
makedepends=('autoconf-archive' 'python')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz"
        'modules-load-thermald.conf')
b2sums=('500189b924594e5b1d68adc776b3ad0c1d531d4259c65dd77f9166648c9b4273c52e1f8222254ec6500b3d37e39deb4ec862443728d50e9be95dee8e43496645'
        '70cdf39afbcc4ea6b0cbe59182714a18755bad8e742f69f9b08e1415dd8f77e00473b9808c46dec3de4e0b5ec17f0bc16d0bd54d61b1e8e77e27901d90aedceb')

build() {
  cd ${_pkgname}-${pkgver}
  ./autogen.sh
  ./configure \
    --prefix=/usr \
    --sysconfdir=/etc \
    --localstatedir=/var \
    --sbindir=/usr/bin
  make
}

package() {
  cd ${_pkgname}-${pkgver}
  DESTDIR="${pkgdir}" make install
  install -Dm644 "${srcdir}"/modules-load-thermald.conf "${pkgdir}"/usr/lib/modules-load.d/thermald.conf
}
