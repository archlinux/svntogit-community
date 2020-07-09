# Maintainer: Balló György <ballogyor+arch at gmail dot com>

pkgname=goobox
pkgver=3.6.0
pkgrel=2
pkgdesc="CD player and ripper for GNOME"
arch=('x86_64')
url="https://people.gnome.org/~paobac/goobox/"
license=('GPL')
depends=('gst-plugins-base' 'brasero' 'libmusicbrainz5' 'libdiscid' 'libcoverart' 'libnotify')
makedepends=('itstool' 'meson')
optdepends=('gst-plugins-good: rip CDs into flac and wav formats')
source=(https://download.gnome.org/sources/$pkgname/${pkgver%.*}/$pkgname-$pkgver.tar.xz)
sha256sums=('5c4cd30463a82dd873f297f27774867ede3e6a8679ee12a12d790508dc46b046')

build() {
  arch-meson $pkgname-$pkgver build
  ninja -C build
}

package() {
  DESTDIR="$pkgdir" meson install -C build
}
