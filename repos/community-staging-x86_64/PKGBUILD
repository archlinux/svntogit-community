# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Marcin Wieczorek <marcin@marcin.co>
# Contributor: ovi chis <ovi@ovios.org>

pkgname=libqb
pkgver=2.0.3
pkgrel=1
pkgdesc='Library for providing high performance, reusable features for client-server architecture'
url='https://github.com/ClusterLabs/libqb'
arch=('x86_64')
license=('LGPL2.1')
depends=('glibc')
makedepends=('doxygen' 'splint')
checkdepends=('check')
provides=('libqb.so')
source=(https://github.com/ClusterLabs/${pkgname}/releases/download/v${pkgver}/${pkgname}-${pkgver}.tar.gz{,.asc})
sha512sums=('85ff46228dbba53e08d6f8426087fd86f1e05591f3c0d822c33c3dd89e7b16d3e91de2fba15cd673c8ff04e66d5cb5243775889fe8df9fdcab8e1e47b6fdd1fc'
            'SKIP')
validpgpkeys=('C5E29348A2B634E9F71B2014791890532CB5CDDE') # libqb Release Signing Key <users@clusterlabs.org>

prepare() {
  cd ${pkgname}-${pkgver}
  ./autogen.sh
}

check() {
  cd ${pkgname}-${pkgver}
  make -C tests VERBOSE=1 check
}

build() {
  cd ${pkgname}-${pkgver}
  ./configure \
    --prefix=/usr \
    --disable-fatal-warnings \
    --disable-static \
    --libdir=/usr/lib \
    --sbindir=/usr/bin \
    --localstatedir=/var
  make
}

package() {
  cd ${pkgname}-${pkgver}
  make DESTDIR="${pkgdir}" install
}

# vim: ts=2 sw=2 et:
