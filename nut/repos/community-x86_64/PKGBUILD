# Maintainer: Maxime Gauduin <alucryd@archlinux.org>
# Contributor: Florian Bruhin <archlinux.org@the-compiler.org>
# Contributor: Alex Reznichenko <sa5gap@yandex.ru>
# Contributor: Roman Kyrylych <roman@archlinux.org>
# Contributor: Giuseppe Lucarelli <luk@rebelsoft.org>
# Contributor: Dan Ziemba <zman0900@gmail.com>

pkgname=nut
pkgver=2.8.0
pkgrel=3
pkgdesc='A collection of programs which provide a common interface for monitoring and administering UPS, PDU and SCD hardware'
arch=(x86_64)
url=https://networkupstools.org/
license=(
  GPL2
  GPL3
)
depends=(
  gcc-libs
  glibc
  libtool
  libusb-compat
  neon
  net-snmp
  openssl
)
makedepends=(
  asciidoc
  gd
  git
  python
  systemd
)
optdepends=('gd: CGI support')
provides=(network-ups-tools)
conflicts=(network-ups-tools)
replaces=(network-ups-tools)
options=(!makeflags)
backup=(
  etc/nut/hosts.conf
  etc/nut/nut.conf
  etc/nut/ups.conf
  etc/nut/upsd.conf
  etc/nut/upsd.users
  etc/nut/upsmon.conf
  etc/nut/upssched.conf
  etc/nut/upsstats.html
  etc/nut/upsstats-single.html
)
_tag=ff16dabca191e5fd8ddc20137317bdebee554d8d
source=(
  git+https://github.com/networkupstools/nut.git#tag=${_tag}
  nut.sysusers
  nut.tmpfiles
  nut-lowspeed-buffer-size.patch
  nut-no-libdummy.patch
  nut-openssl-1.1.patch
  nut-snmp-usb-order.patch
)
b2sums=('SKIP'
        'b136678723bae38f2e1b99d682e5bad6c4387c2d709052681f1dc0d41e8dd6d061115f6d3e573400bded671296ca61e5e194258e801c83f26bf309313b3f2319'
        'b5466d4142fdeadd07859c030a9e6f7a73f1a4f3902a07b6e8b9a5ead738279ff557ac21770edef21e55b015a3b19cd9579e638da0a37f102ed130ed749ac03b'
        'cdd11335a8d60b2cada25a2cd9be2d0f1c911029a46e3adf8eda7d8687c1b2caf0fd66cd92c41ecbd660d44bc2606e92aa81d4a2c9746b2ef9e15c4048679487'
        '0314fe2358fab9d49a8bc5b939c2855151c4f35b2b51e6d1accf25469c9d55831960cd5f9b53ee151fb5a45ae7068c9bfcc91c84a7623b783f6c3c5d5da75d65'
        '17877276e46372aa17d357efc0851b9cdb33b14ac0c40913b47ea513a8ecaa6eebe3241ae8b324583070d76b6c12d3cf18c043778754b5774af846fb8a33b4d7'
        'e39f049413cb3d393befe5795c895128271f4ca2791b5723eba5c5f20be0b770369ee6144a1e5d6793727709b1ba578d8ace6cbf91695a2771453047827e5334')

pkgver() {
  cd nut
  git describe --tags | sed 's/^v//'
}

prepare() {
  cd nut
  ./autogen.sh
}

build() {
  cd nut
  ./configure \
    --prefix=/usr \
    --datadir=/usr/share/nut \
    --libexecdir=/usr/lib/nut \
    --sbindir=/usr/bin \
    --sysconfdir=/etc/nut \
    --disable-static \
    --with-user=nut \
    --with-group=nut \
    --with-altpidpath=/run/nut \
    --with-cgipath=/usr/share/nut/cgi \
    --with-drvpath=/usr/lib/nut \
    --with-htmlpath=/usr/share/nut/html \
    --with-pidpath=/run/nut \
    --with-statepath=/var/lib/nut \
    --with-systemdsystemunitdir=/usr/lib/systemd/system \
    --with-udev-dir=/usr/lib/udev \
    --with-cgi \
    --with-dev \
    --with-doc=man \
    --with-libltdl \
    --with-neon \
    --with-openssl \
    --with-serial \
    --with-snmp \
    --with-usb \
    --without-avahi \
    --without-ipmi \
    --without-freeipmi \
    --without-powerman \
    --without-wrap
  make
}

package() {
  make DESTDIR="${pkgdir}" -C nut install
  find "${pkgdir}"/etc/nut -name *.sample -exec rename '.sample' '' {} \;
  install -Dm 644 nut.sysusers "${pkgdir}"/usr/lib/sysusers.d/nut.conf
  install -Dm 644 nut.tmpfiles "${pkgdir}"/usr/lib/tmpfiles.d/nut.conf
}

# vim: ts=2 sw=2 et:
