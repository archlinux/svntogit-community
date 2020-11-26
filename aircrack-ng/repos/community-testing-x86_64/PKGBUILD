# Maintainer: Jonathan Steel <jsteel at archlinux.org>
# Contributor: Brad Fanella <bradfanella@archlinux.us>
# Contributor: Daenyth <Daenyth+Arch [at] gmail [dot] com>
# Contributor: Corrado Primier <bardo@aur.archlinux.org>
# Contributor: ice-man <icemanf@gmail.com>

pkgname=aircrack-ng
_pkgver=1.6
pkgver=${_pkgver//-/}
pkgrel=3
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
source=(https://download.aircrack-ng.org/$pkgname-$_pkgver.tar.gz
        $pkgname-$_pkgver-airgraphviz-py.patch::https://github.com/aircrack-ng/aircrack-ng/commit/5815bfe2ede99c094709a3289172335c3ba5b255.patch
        $pkgname-$_pkgver-airgraphviz-make.patch::https://github.com/aircrack-ng/aircrack-ng/commit/b9ee19bcf868d4f4f0197cb0d886d0ebe91a6636.patch)
sha256sums=('4f0bfd486efc6ea7229f7fbc54340ff8b2094a0d73e9f617e0a39f878999a247'
            '6b091cf250b4c09475f0c70428f0d8471a4fc2ffaff5edc67548b69cb4cda1e8'
            '89549000a3016ec98def974fbbb913b759861aa654f43fd3e3e2b0951955dbfa')

prepare() {
  cd $pkgname-$_pkgver
  patch -Np1 < ../$pkgname-$_pkgver-airgraphviz-py.patch
  patch -Np1 < ../$pkgname-$_pkgver-airgraphviz-make.patch
  autoreconf -fiv
}

build() {
  cd $pkgname-$_pkgver

  CFLAGS+=' -fcommon' # https://github.com/aircrack-ng/aircrack-ng/issues/2138

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
