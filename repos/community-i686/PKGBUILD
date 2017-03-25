# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgname=thermald
_pkgname=thermal_daemon
pkgver=1.6
pkgrel=1
pkgdesc="The Linux Thermal Daemon program from 01.org"
arch=('i686' 'x86_64')
url="https://01.org/linux-thermal-daemon"
license=('GPL2')
makedepends=('systemd')
depends=('dbus-glib' 'libxml2')
backup=('etc/thermald/thermal-conf.xml')
source=(${pkgname}-${pkgver}.tar.gz::"https://github.com/01org/${_pkgname}/archive/v${pkgver}.tar.gz"
        'modules-load-thermald.conf')
sha256sums=('c63ae1b031f2b4ce037441e7e9910d05405b540fe6668e156d32c56d5dfa7492'
            '0155e1eb459306d251a5a049ffc6c11e144fa8caa75901ac5fa20bd52e05d515')

build() {
  cd ${_pkgname}-${pkgver}
  ./autogen.sh
  ./configure --prefix=/usr \
              --sysconfdir=/etc \
              --localstatedir=/var \
              --sbindir=/usr/bin
  make
}

package() {
  cd ${_pkgname}-${pkgver}

  make DESTDIR="${pkgdir}" install

  install -Dm644 "${srcdir}"/modules-load-thermald.conf "${pkgdir}"/usr/lib/modules-load.d/thermald.conf

  # Remove Upstart related files
  rm -r "${pkgdir}/etc/init"
}
