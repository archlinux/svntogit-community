# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Geoffroy Carrier <geoffroy.carrier@koon.fr>

pkgbase=lxtask
pkgname=(lxtask lxtask-gtk3)
pkgver=0.1.10
pkgrel=2
pkgdesc='Task manager of the LXDE Desktop'
arch=('x86_64')
license=('GPL2')
url='https://lxde.org/'
depends=('gtk2' 'gtk3')
makedepends=('intltool')
source=(https://downloads.sourceforge.net/lxde/$pkgbase-$pkgver.tar.xz)
sha256sums=('2216df9bc4bb2d80733e788966512ac58c421e0a0a1ff85210f34a29d1eb4e2c')

build() {
  # GTK+ 2 version
  [ -d gtk2 ] || cp -r $pkgbase-$pkgver gtk2
  cd gtk2
  ./configure --sysconfdir=/etc --prefix=/usr
  make

  cd "$srcdir"
  # GTK+ 3 version
  [ -d gtk3 ] || cp -r $pkgbase-$pkgver gtk3
  cd gtk3
  ./configure --sysconfdir=/etc --prefix=/usr --enable-gtk3
  make
}

package_lxtask() {
  groups=('lxde')
  depends=('gtk2')

  cd gtk2
  make DESTDIR="$pkgdir" install
}

package_lxtask-gtk3() {
  groups=('lxde-gtk3')
  pkgdesc+=' (GTK+ 3 version)'
  depends=('gtk3')
  conflicts=('lxtask')

  cd gtk3
  make DESTDIR="$pkgdir" install

  # Ignore package by AppStream to avoid duplicated IDs
  echo 'X-AppStream-Ignore=true' >> "$pkgdir/usr/share/applications/$pkgbase.desktop"
}
