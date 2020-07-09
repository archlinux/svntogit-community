# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Filipp "Scorp" Andjelo <scorp@mailueberfall.de>

pkgbase=lxinput
pkgname=(lxinput lxinput-gtk3)
pkgver=0.3.5
pkgrel=3
pkgdesc="Small program to configure keyboard and mouse for LXDE"
arch=('x86_64')
url="https://lxde.org/"
license=('GPL')
groups=('lxde')
depends=('gtk2' 'gtk3')
makedepends=('intltool')
source=(https://downloads.sourceforge.net/lxde/$pkgbase-$pkgver.tar.xz)
sha256sums=('4e8f778a65a4afe2365b47e7899358aa4fab535343aa62c72a3cdc4cac1f6e88')

build() {
  # GTK+ 2 version
  [ -d gtk2 ] || cp -r $pkgbase-$pkgver gtk2
  cd gtk2
  ./configure --prefix=/usr
  make

  cd "$srcdir"
  # GTK+ 3 version
  [ -d gtk3 ] || cp -r $pkgbase-$pkgver gtk3
  cd gtk3
  ./configure --prefix=/usr --enable-gtk3
  make
}

package_lxinput() {
  groups=('lxde')
  depends=('gtk2')

  cd gtk2
  make DESTDIR="$pkgdir" install
}

package_lxinput-gtk3() {
  groups=('lxde-gtk3')
  pkgdesc+=' (GTK+ 3 version)'
  depends=('gtk3')
  conflicts=('lxinput')

  cd gtk3
  make DESTDIR="$pkgdir" install
}
