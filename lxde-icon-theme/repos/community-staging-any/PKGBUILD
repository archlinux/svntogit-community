# Maintainer: Balló György <ballogyor+arch at gmail dot com>
# Contributor: Angel Velasquez <angvp@archlinux.org>
# Contributor: Juergen Hoetzel <juergen@archlinux.org>

pkgname=lxde-icon-theme
pkgver=0.5.1
pkgrel=5
pkgdesc="LXDE default icon theme based on nuoveXT2"
arch=('any')
url="https://lxde.org/"
license=('GPL')
groups=('lxde' 'lxde-gtk3')
depends=('gtk-update-icon-cache')
source=(https://downloads.sourceforge.net/lxde/$pkgname-$pkgver.tar.xz)
md5sums=('7467133275edbbcc79349379235d4411')

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
}
