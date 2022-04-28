# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Michael Düll <mail@akurei.me>

pkgname=rtl-sdr
pkgver=0.8.0
pkgrel=4
epoch=1
pkgdesc="Driver for Realtek RTL2832U, allowing general purpose software defined radio (SDR)."
arch=('x86_64')
url="https://sdr.osmocom.org/trac/wiki/rtl-sdr"
license=('GPL')
depends=('libusb>=1.0')
makedepends=('git' 'cmake')
conflicts=('rtl-sdr-git')
options=('staticlibs') 
install=rtl-sdr.install
#source=("git://git.osmocom.org/rtl-sdr.git#tag=$pkgver"
source=("rtl-sdr.$pkgver.tgz::https://github.com/librtlsdr/librtlsdr/archive/v$pkgver.tar.gz"
        'rtlsdr.conf')
sha512sums=('afef8508ccc1313470e8f5440fd7104298be23737eeae03954be912f93b6000317ec354412939c95956d3958ec4bf6e437d5ddb8817479b210dd5da544fc0a47'
            '45be9e6d5b6ab0db3c3210173e5eb76067236e098a5f27552706fd6adcbbd09cc3eeeaaa30efb1a24930543a89ee26806bb3b37135e4a53a62db00dcaaedea74')

_gitname="rtl-sdr"

# todo: fix upstream's udev rule location and group

#pkgver() {
#  cd "$srcdir/$_gitname"
#  git show -s --format="%ci" HEAD | sed -e 's/-//g' -e 's/ .*//'
#}

build() {
  #cd "$srcdir/$_gitname"
  cd "$srcdir/librtlsdr-$pkgver"
  mkdir -p build
  cd build
  cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr \
        -DCMAKE_C_FLAGS="$CFLAGS -ffat-lto-objects" \
        -DDETACH_KERNEL_DRIVER=ON -Wno-dev ../
  make
}

package() {
  #cd "$srcdir/$_gitname/build"
  cd "$srcdir/librtlsdr-$pkgver/build"
  make DESTDIR="$pkgdir" install
  install -Dm644 "$srcdir/librtlsdr-$pkgver/rtl-sdr.rules" "$pkgdir/usr/lib/udev/rules.d/10-rtl-sdr.rules"
  install -Dm644 "$srcdir/rtlsdr.conf" "$pkgdir/usr/lib/modprobe.d/rtlsdr.conf"
}

# vim:set ts=2 sw=2 et:
