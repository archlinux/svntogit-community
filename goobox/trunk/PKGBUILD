# Maintainer: Balló György <ballogyor+arch at gmail dot com>

pkgname=goobox
pkgver=3.4.3
pkgrel=1
pkgdesc="CD player and ripper for GNOME"
arch=('x86_64')
url="https://people.gnome.org/~paobac/goobox/"
license=('GPL')
depends=('gst-plugins-base' 'brasero' 'libmusicbrainz5' 'libdiscid' 'libcoverart' 'libnotify')
makedepends=('intltool' 'itstool' 'python')
optdepends=('gst-plugins-good: rip CDs into flac and wav formats')
source=(https://download.gnome.org/sources/$pkgname/${pkgver%.*}/$pkgname-$pkgver.tar.xz)
sha256sums=('7f97cfc1887acc26f7435a5078c710a422c7a7747f94a09e1ed4a904284848e2')

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var \
              --disable-schemas-compile
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
