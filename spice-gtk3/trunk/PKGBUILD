# Maintainer: Stefano Facchini <stefano.facchini@gmail.com>
# Contributor: Jonathan Lestrelin <zanko@daemontux.org>
# Derived from the spice-gtk PKGBUILD by
# Contributor: Lucio Zara <pennega@gmail.com>

pkgname=spice-gtk3
_pkgname=spice-gtk
pkgver=0.20
pkgrel=1
pkgdesc="A Gtk client and libraries for SPICE remote desktop servers (gtk3 version)."
arch=('x86_64' 'i686')
url="http://spice-space.org"
license=('GPL')
makedepends=('intltool' 'vala' 'python2-pyparsing')
depends=('libpulse' 'gtk3' 'spice' 'libusb' 'usbredir')
conflicts=('spice-gtk')
options=('!libtool')
source=("http://www.spice-space.org/download/gtk/$_pkgname-$pkgver.tar.bz2")
sha256sums=('b1355823b0ceb2e118c1f9a9a602ccab78e1e2edf2d93f71fa42d3bc85ca75df')

build() {
  cd "$srcdir/$_pkgname-$pkgver"

  sed -i 's,/usr/bin/env python,/usr/bin/python2,' spice-common/spice_codegen.py

  ./configure --prefix=/usr \
              --with-gtk=3.0 \
              --with-python \
              --enable-vala
  make
}

package() {
  cd "$srcdir/$_pkgname-$pkgver"

  make DESTDIR="$pkgdir/" install
}
