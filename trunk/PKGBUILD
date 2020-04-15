# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=urjtag
pkgver=2019.12
pkgrel=1
pkgdesc='Enhanced, modern tool for communicating over JTAG with flash chips, CPUs, and many more'
arch=('x86_64')
url='http://openocd.org'
license=('GPL')
depends=('libftdi-compat' 'libusb-compat')
makedepends=('python')
optdepends=('python: Python bindings')
source=("https://downloads.sourceforge.net/sourceforge/$pkgname/$pkgver/$pkgname-$pkgver.tar.xz")
sha512sums=('e149e53410a6591bdadc2c0138c6f81dac0fd6e35601461e19d356decdb820ec8e6bd53d59a1fd9781dfa1fee88d23dcafbd8df9adc0f8e51256c626d2ee0f36')

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
