# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=urjtag
pkgver=2021.03
pkgrel=3
pkgdesc='Enhanced, modern tool for communicating over JTAG with flash chips, CPUs, and many more'
arch=('x86_64')
url='http://urjtag.org'
license=('GPL')
depends=('libftdi-compat' 'libusb-compat')
makedepends=('python')
optdepends=('python: Python bindings')
source=("https://downloads.sourceforge.net/sourceforge/$pkgname/$pkgver/$pkgname-$pkgver.tar.xz")
sha512sums=('baf203e556d1d41437539d3f5c018b35fbb496f71391c2bec2786ffa47bff33d38654b3e7d106e38bcf36d075d86fc02b18eaaf634cdb65e2840ff50ca0da8b2')

build() {
  cd $pkgname-$pkgver

  autoreconf -vif

  ./configure \
        --prefix=/usr \
        --enable-svf \
        --enable-bsdl \
        --enable-stapl \
        --enable-python

  make
}

package() {
  cd $pkgname-$pkgver

  make DESTDIR="$pkgdir" install
}
