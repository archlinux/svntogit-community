# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.4.4
pkgrel=1
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2' 'libevdev' 'upower')
makedepends=('autoconf-archive' 'python' 'gtk-doc')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz"
        'modules-load-thermald.conf')
b2sums=('26ca1af1693a5f67c327a97784a06f86f7debc87a5ba928de2edf1b16f92d4b39771e8df4bbdc2d1dd314c60f837c5c550bb7b7854bce4d4647a096653ac2931'
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
