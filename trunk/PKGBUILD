# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Jonathan Steel <jsteel at archlinux.org>
# Contributor: Brad Fanella <bradfanella@archlinux.us>
# Contributor: Daenyth <Daenyth+Arch [at] gmail [dot] com>
# Contributor: Corrado Primier <bardo@aur.archlinux.org>
# Contributor: ice-man <icemanf@gmail.com>

pkgname=aircrack-ng
_pkgver=1.7
pkgver=${_pkgver//-/}
pkgrel=3
pkgdesc="Key cracker for the 802.11 WEP and WPA-PSK protocols"
arch=('x86_64')
url="https://www.aircrack-ng.org"
license=('GPL2')
depends=('glibc' 'gcc-libs' 'openssl' 'sqlite' 'iw' 'net-tools' 'wireless_tools' 'ethtool'
         'pcre' 'libpcap' libpcap.so 'python' 'zlib' 'libnl' 'hwloc' 'usbutils')
checkdepends=('cmocka')
conflicts=('aircrack-ng-scripts')
replaces=('aircrack-ng-scripts')
provides=('aircrack-ng-scripts')
source=(https://download.aircrack-ng.org/$pkgname-$_pkgver.tar.gz)
sha256sums=('05a704e3c8f7792a17315080a21214a4448fd2452c1b0dd5226a3a55f90b58c3')
b2sums=('4461af7b698d30c96e6f93494d5ee658bf8d7144d8b165e9b8aee1766a35dddded3bbb738237e1100dcf22167125aa7cf9149288bba1607fe778470b04596cb2')

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
