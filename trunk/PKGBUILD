# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org> 
# Contributor: Geoffroy Carrier <geoffroy.carrier@koon.fr>

pkgname=lxterminal
pkgver=0.4.0
pkgrel=1
pkgdesc="VTE-based terminal emulator (part of LXDE)"
arch=('x86_64')
url="https://lxde.org/"
license=('GPL2')
groups=('lxde' 'lxde-gtk3')
depends=('vte3')
makedepends=('intltool')
conflicts=('lxterminal-gtk3')
replaces=('lxterminal-gtk3')
source=(https://downloads.sourceforge.net/lxde/${pkgname}-${pkgver}.tar.xz)
sha256sums=('9db8748923b3fa09a82ae2210ed1fa4cdb4c45312009da9caed103d48f8e9be7')

build() {
  cd $pkgname-$pkgver
  ./configure --sysconfdir=/etc --prefix=/usr --enable-gtk3
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
