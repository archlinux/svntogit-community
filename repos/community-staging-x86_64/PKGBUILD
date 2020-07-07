# Maintainer: Alexander F Rødseth <xyproto@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>   
# Contributor: Patrick Melo <patrick@patrickmelo.eti.br>

pkgname=ctpl
pkgver=0.3.4
pkgrel=4
pkgdesc='Template engine library written in C'
arch=('x86_64')
url='https://ctpl.tuxfamily.org/'
license=('GPL')
depends=('glib2')
source=("https://download.tuxfamily.org/ctpl/releases/$pkgname-$pkgver.tar.gz")
sha256sums=('3a95fdd03437ed3ae222339cb0de2d2c1240d627faa6c77bf46f1a9b761729fb')

build() {
  cd "$pkgname-$pkgver"

  ./configure --prefix=/usr
  make 
}

package() {
  make -C "$pkgname-$pkgver" DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
