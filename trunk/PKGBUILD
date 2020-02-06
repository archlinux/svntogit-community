# Maintainer: Jonathan Steel <jsteel at archlinux.org>
# Contributor: Brad Fanella <bradfanella@archlinux.us>
# Contributor: Daenyth <Daenyth+Arch [at] gmail [dot] com>
# Contributor: Corrado Primier <bardo@aur.archlinux.org>
# Contributor: ice-man <icemanf@gmail.com>

pkgname=aircrack-ng
_pkgver=1.6
pkgver=${_pkgver//-/}
pkgrel=1
pkgdesc="Key cracker for the 802.11 WEP and WPA-PSK protocols"
arch=('x86_64')
url="https://www.aircrack-ng.org"
license=('GPL2')
depends=('openssl' 'sqlite' 'iw' 'net-tools' 'wireless_tools' 'ethtool'
         'pcre' 'libpcap' 'python' 'zlib' 'libnl' 'hwloc')
checkdepends=('cmocka')
conflicts=('aircrack-ng-scripts')
replaces=('aircrack-ng-scripts')
provides=('aircrack-ng-scripts')
source=(https://download.aircrack-ng.org/$pkgname-$_pkgver.tar.gz)
sha256sums=('4f0bfd486efc6ea7229f7fbc54340ff8b2094a0d73e9f617e0a39f878999a247')

prepare() {
  cd $pkgname-$_pkgver
  autoreconf -fiv
}

build() {
  cd $pkgname-$_pkgver

  ./configure \
    --prefix=/usr \
    --libexecdir=/usr/lib \
    --sbindir=/usr/bin \
    --with-ext-scripts \
    --with-experimental

  make
}

check() {
  cd $pkgname-$_pkgver

  make check
}

package() {
  cd $pkgname-$_pkgver

  make DESTDIR="$pkgdir" install
}

# vim: ts=2 sw=2 et:
