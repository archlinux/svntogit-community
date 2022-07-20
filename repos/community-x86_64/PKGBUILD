# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor:Francois Menning <f.menning@pm.me>
# Contributor: gilbus <aur(AT)tinkershell.eu>
# Contributor: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=2.5
pkgrel=1
pkgdesc='The Linux Thermal Daemon program from 01.org'
arch=('x86_64')
url='https://01.org/linux-thermal-daemon'
license=('GPL2')
depends=('dbus-glib' 'libxml2' 'libevdev' 'upower')
makedepends=('autoconf-archive' 'python' 'gtk-doc')
source=("https://github.com/intel/thermal_daemon/archive/v${pkgver}/${_pkgname}-${pkgver}.tar.gz")
b2sums=('df7004cdd9f0a36479f7d8c129338ac9b2fd3b4deca188ef3568336c448f563460ca74203384694f37a29fd7ba71b52d356f861d28313e52b443a81557ea406e')

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
